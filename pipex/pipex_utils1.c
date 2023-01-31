/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboulgh <oaboulgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 20:38:27 by oaboulgh          #+#    #+#             */
/*   Updated: 2023/01/31 01:46:15 by oaboulgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_putstr(int fd, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*arr;
	char	*to_find;

	i = 0;
	j = 0;
	arr = (char *)haystack;
	to_find = (char *)needle;
	if (to_find[i] == 0)
		return (arr);
	if (haystack == NULL && len == 0)
		return (0);
	while (arr[i] && i < len)
	{
		while (to_find[j] == arr[i + j] && (i + j) < len)
		{
			j++;
			if (to_find[j] == '\0' && i <= len - j)
				return (&arr[i]);
		}
		i++;
		j = 0;
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*p2;

	if (!s1 || !s2)
		return (0);
	p2 = (malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1));
	if (!p2)
		return (0);
	i = ft_strlen(s1);
	ft_memcpy(p2, s1, i);
	p2 = p2 + i;
	ft_memcpy(p2, s2, ft_strlen(s2)+1);
	p2 = p2 - i;
	return (p2);
}

char	*ft_strdup(const char *s1)
{
	char	*new;
	int		i;

	i = 0;
	new = (char *)(malloc(sizeof(char) * (ft_strlen(s1) + 1)));
	if (new == NULL)
		return (0);
	while (*s1)
		new[i++] = *s1++;
	new[i] = '\0';
	return (new);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*arr;
	const unsigned char	*source;
	size_t				i;

	source = src;
	arr = dst;
	i = 0;
	if (dst == src)
		return (dst);
	while (i < n)
	{
		arr[i] = source[i];
		i++;
	}
	return (dst);
}
