/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils4_bouns.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboulgh <oaboulgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:24:40 by oaboulgh          #+#    #+#             */
/*   Updated: 2023/02/02 16:24:50 by oaboulgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

size_t	ft_count_strings(char const *str, char c)
{
	size_t		i;
	size_t		j;
	size_t		k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i])
	{
		if (str[i] != c && j == 0)
		{
			j = 1;
			k++;
		}
		else if (str[i] == c)
		{
			j = 0;
		}
		i++;
	}
	return (k);
}

size_t	ft_count_char(char const *s, size_t i, char c)
{
	size_t	len;

	len = 0;
	while (s[i] != c && s[i])
	{
		len++;
		i++;
	}
	return (len);
}

char	**free_all(char **s, size_t i)
{
	while (i >= 0 && s[i] != NULL)
	{
		free(s[i]);
		s[i] = NULL;
		i--;
	}
	free(s);
	s = NULL;
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	size_t	sum_of_size;
	char	*p;

	if (ft_strlen(s) < start)
		return (ft_strdup("\0"));
	sum_of_size = ft_strlen(s + start);
	j = 0;
	if (sum_of_size < len)
		len = sum_of_size;
	p = malloc((len + 1) * sizeof(char));
	if (!p)
		return (0);
	while (j < len)
		p[j++] = s[start++];
	p[j] = '\0';
	return (p);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**strs;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	strs = (char **)(malloc(sizeof(char *) * (ft_count_strings(s, c) + 1)));
	if (!strs)
		return (0);
	while (j < ft_count_strings(s, c))
	{
		while (s[i] == c && s[i])
			i++;
		strs[j] = ft_substr(&s[i], 0, (ft_count_char(s, i, c)));
		if (!strs[j] && j < ft_count_strings(s, c))
			return (free_all(strs, j));
		i += ft_count_char(s, i, c);
		j++;
	}
	strs[j] = 0;
	return (strs);
}
