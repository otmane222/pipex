/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboulgh <oaboulgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:18:00 by oaboulgh          #+#    #+#             */
/*   Updated: 2023/01/31 01:55:24 by oaboulgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_amount(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	return (i - 1);
}

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (i < n && (str1[i] != '\0' || str2[i] != '\0'))
	{
		if (str1[i] > str2[i])
			return (1);
		else if (str1[i] < str2[i])
			return (-1);
		i++;
	}
	return (0);
}

void	error_found(char *str)
{
	write(1, "zsh: command not found: ", 24);
	write(1, str + 1, ft_strlen(str - 1));
	write(1, "\n", 1);
}

void	ft_heredoc_handler(t_pipex *data, char **av)
{
	int		i;
	int		fp;
	char	*str;

	i = 0;
	data->flag = 0;
	data->amount = data->amount;
	fp = open("temp_file", O_CREAT | O_RDWR, 0777);
	av[2] = ft_strjoin(av[2], "\n");
	while (1)
	{
		write(1, "pipe heredoc> ", 15);
		str = get_next_line(STDIN_FILENO);
		if (ft_strncmp(str, av[2], ft_strlen(av[2])) == 0)
			break ;
		ft_putstr(fp, str);
		free(str);
	}
	free(str);
	str = NULL;
}

int	check_here_doc(char *str)
{
	int		i;

	i = 0;
	if (ft_strncmp(str, "here_doc", 8) == 0)
		return (1);
	return (0);
}
