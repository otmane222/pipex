/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils1_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboulgh <oaboulgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 02:25:09 by oaboulgh          #+#    #+#             */
/*   Updated: 2023/02/03 16:31:18 by oaboulgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	check_word_path(char *env)
{
	if (ft_strnstr(env, "PATH", 5) != NULL)
		return (0);
	return (1);
}

int	check_file_name(t_pipex *data, char **av)
{
	data->i = 4;
	data->fd3 = open(av[1], O_RDONLY);
	if (data->fd3 == -1 && !(check_here_doc(av[1])))
	{
		if (data->flag)
			ft_printf("zsh: no such file or directory: %s\n", av[1]);
		data->flag = 0;
		data->i += 1;
		return (0);
	}
	return (1);
}

void	free_all2(char **str, t_pipex	*data)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(data);
	free(str);
	str = NULL;
}
