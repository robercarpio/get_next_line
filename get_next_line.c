/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarpio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 19:31:47 by rcarpio-          #+#    #+#             */
/*   Updated: 2024/10/30 19:31:50 by rcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char *storage = NULL;
	char	*buffer;
	int	rd;
	char *tmp;

	buffer = (char *)malloc(BUFFER_SIZE+1);
	if (!buffer)
		return (NULL);
	//printf("%s","prerd");
	rd = read(fd, buffer, BUFFER_SIZE);
	//printf("%s","postrd");
	if (rd <= 0)
		return (NULL);
	while (rd > 0)
	{
		if (!storage)
		{
			storage = ft_strdup(buffer);
			//free (buffer);
		}
		else {
			if (!ft_strchr(buffer,'\n'))
			{
				/*
				storage = ft_strjoin(storage,buffer);
				free(buffer);
				*/
				tmp = ft_strjoin(storage, buffer);
				free(storage);
				storage = tmp;

			}
		}

		if (!ft_strchr(storage,'\n'))
		{
			rd = read(fd, buffer, BUFFER_SIZE);
		}
		else
			break;
	}
	//if(buffer)
		//free(buffer);
	return (ft_aux(&storage));
}


char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	int		i;
	size_t	r_len;

	if (!s1 || !s2)
		return (NULL);
	r_len = ((ft_strlen(s1) + ft_strlen(s2)) + 1);
	ptr = malloc(r_len);
	if (!ptr)
		return (NULL);
	i = 0;
	while (*s1)
	{
		ptr[i] = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		ptr[i] = *s2;
		s2++;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_aux(char **stg)
{
	char	*sta;
	char	*dp;

	sta = NULL;
	if (!ft_strchr(*stg,'\n')+1)
	{
		dp = ft_strdup(*stg);
		free(*stg);
		return (dp);
	}
	else{
		sta = (char *)malloc(ft_indexof(*stg,'\n')+2);
		if (!sta)
			return(NULL);
		sta = ft_substr(*stg,0,ft_indexof(*stg,'\n')+1);
		*stg = ft_strchr(*stg,'\n')+1;
	}
	return (sta);
}

size_t	ft_strlen(char *str)
{
	if (!str)
		return (0);
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
int main(void)
{
	int	fd;
	fd = open("test.txt",O_RDONLY);
	printf("%s",get_next_line(fd));
	return (0);
}