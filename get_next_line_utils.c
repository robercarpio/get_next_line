/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarpio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 19:32:29 by rcarpio-          #+#    #+#             */
/*   Updated: 2024/10/30 19:32:32 by rcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int				b;
	unsigned char	ch;

	if (!s)
		return (NULL);
	ch = c;
	b = 0;
	while (*s && b != 1)
	{
		if (*s != ch)
			s++;
		else
			b = 1;
	}
	if (!*s && ch != '\0')
		return (0);
	return ((char *)s);
}
char	*ft_strdup(const char *s)
{
	char	*str;

	str = malloc((ft_strlen(s) + 1));
	if (str != NULL)
	{
		ft_memcpy(str, s, ft_strlen(s) + 1);
		return (str);
	}
	return (str);
}

void	ft_strcpy(char *dst, const char *src)
{
	size_t	i;
	size_t	r;

	i = 0;
		while (src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
}

int	ft_indexof(char *str, char c)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str == c)
			return (i);
			i++;
			str++;
	}
	return (-1);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	len_s;

	len_s = ft_strlen(s);
	if (start >= len_s)
	{
		return (ft_strdup(""));
	}
	if (len > len_s - start)
		len = len_s - start;
	substr = (char *)malloc(len + 1);
	if (!substr)
		return (0);
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}



