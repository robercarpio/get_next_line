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
	storage = NULL;
	return (ft_aux());
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

int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	printf("%s \n",get_next_line(fd));

	return (0);
}

char	*ft_aux(char *stg)
{
	if ()
}