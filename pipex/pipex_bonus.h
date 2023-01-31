/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboulgh <oaboulgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:28:52 by oaboulgh          #+#    #+#             */
/*   Updated: 2023/01/31 02:01:40 by oaboulgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include "get_next_line.h"
# include <sys/wait.h>
# include <time.h>

typedef struct s_pipex
{
	char	**avvec;
	char	**acvec;
	char	*path;
	int		fd3;
	int		fd4;
	int		fd5;
	int		fd6;
	int		amount;
	int		flag;
	int		i;
	int		count;
	int		id;
}	t_pipex;

int		**creat_pipes(t_pipex *data, char **av);
int		ft_amount(char **av);
int		check_here_doc(char *str);
void	ft_heredoc_handler(t_pipex *data, char **av);
int		check_word_path(char *env);
void	ft_putstr(int fd, char *str);
int		ft_strncmp(char *s1, char *s2, size_t n);
void	error_found(char *str);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**free_all(char **s, size_t i);
size_t	ft_count_char(char const *s, size_t i, char c);
size_t	ft_count_strings(char const *str, char c);
char	*ft_strdup(const char *s1);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	**get_env(char **env);
char	*check_path2(char **paths, char *path);

#endif