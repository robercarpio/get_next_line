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

char	*ft_strchr(char *s, int c)
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
char	*ft_strdup(char *s)
{
	if (!s)
		return (NULL);
	char	*str;

	str = malloc((ft_strlen(s) + 1));
	if (str != NULL)
	{
		ft_memcpy(str, s, ft_strlen(s) + 1);
		return (str);
	}
	else
		return(NULL);
	return (str);
}


int	ft_indexof(char *str, char c)
{
	if (!str)
		return (0);
	int	i;

	i = 0;
	while (*str)
	{
		if (*str == c)
		{
			return (i);
			i++;
			str++;
		}
	}
	return (-1);
}
char	*ft_substr(char *s, unsigned int start, size_t len)
{
	if (!s)
		return (NULL);
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
void	*ft_memcpy(void *dest, void *src, size_t n)
{
	if (!dest || !src)
		return (NULL);
	unsigned char		*ptdest;
	const unsigned char	*ptsrc;
	size_t				i;

	ptdest = dest;
	ptsrc = src ;
	i = 0;
	if (!ptdest && !ptsrc)
		return (NULL);
	while (i < n)
	{
		ptdest[i] = ptsrc[i];
		i++;
	}
	return (dest);
}
size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	if (!dst || !src)
		return (0);
	size_t	i;
	size_t	r;

	i = 0;
	r = 0;
	while (src[r] != '\0')
	{
		r++;
	}
	if (size == 0)
		return (r);
	if (size > 0)
	{
		while (i < size - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (r);
}



