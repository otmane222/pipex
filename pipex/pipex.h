/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboulgh <oaboulgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 14:33:08 by oaboulgh          #+#    #+#             */
/*   Updated: 2023/02/03 16:38:41 by oaboulgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/wait.h>
# include <time.h>

typedef struct s_pipex
{
	char	**avvec;
	char	**env;
	char	*path;
	int		fd3;
	int		fd4;
	int		id;
}	t_pipex;

char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
void	ft_putstr2(int fd, char *str);
void	free_all2(char **str, t_pipex	*data);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**free_all(char **s, size_t i);
size_t	ft_count_char(char const *s, size_t i, char c);
size_t	ft_count_strings(char const *str, char c);
char	*ft_strdup(const char *s1);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

#endif