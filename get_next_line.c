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
	static char *storage;
	char	*buffer;
	int	rd;

	buffer = (char *)malloc(BUFFER_SIZE+1);
	storage = NULL;
	rd = read(fd,buffer,BUFFER_SIZE);
	if (rd <=0)
		return (NULL);
	while (rd > 0)
	{
		if (!storage)
		{
			storage = buffer;
			free (buffer);
		}
		else {
			if (!strchr(buffer,'\n'))
			{
				storage = ft_strjoin(storage,buffer);
				free(buffer);
			}
		}

		if (!strchr(storage,'\n'))
		{
			rd = read(fd,buffer,BUFFER_SIZE);
		}
		else
			break;
	}
	return (ft_aux(&storage));
}
char	*ft_strjoin(char const *s1, char const *s2)
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
	char *q;
	char	*dp;

	sta = NULL;
	if (!strchr(stg,'\n')+1)
	{
		dp = ft_strdup(stg);
		free(stg);
		return (dp);
	}
	else{
		sta = (char *)malloc(indexof(stg,'\n')+2);
		sta = ft_strchr(stg,'\n')+1;
		q = ft_substr(stg,0,indexof(stg,'\n')+1);
		free(*stg);
		*stg = sta;
	}
	return (stg);
}

int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	printf("%s \n",get_next_line(fd));

	return (0);
}
