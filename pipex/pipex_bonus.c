/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboulgh <oaboulgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:28:26 by oaboulgh          #+#    #+#             */
/*   Updated: 2023/02/03 16:20:17 by oaboulgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	**get_path(char **env, t_pipex *data, int fd[2], char **av)
{
	int		i;
	char	**rtn;

	if (pipe(fd) == -1)
		perror("Error");
	data->flag = 1;
	check_file_name(data, av);
	if (check_here_doc(av[1]))
		data->i = 5;
	i = 0;
	data->id = fork();
	while (check_word_path(env[i]) && env[i])
		i++;
	if (env[i])
	{
		rtn = ft_split(env[i] + 5, ':');
		return (rtn);
	}
	return (NULL);
}

char	*check_path2(char **avvec, char *cmd)
{
	int		i;
	char	*str;

	i = 0;
	if (access(cmd, X_OK) == 0)
		return (cmd);
	cmd = ft_strjoin("/", cmd);
	while (avvec[i])
	{
		str = ft_strjoin(avvec[i], cmd);
		if (access(str, X_OK) == 0)
			return (str);
		i++;
	}
	return (NULL);
}

void	executing_pipe(int *fd, char **av, char **env, t_pipex *data)
{
	close(fd[0]);
	if (check_here_doc(av[data->i - 4]) == 1)
		ft_heredoc_handler(data, av);
	data->acvec = ft_split(av[data->i - 2], ' ');
	data->path = check_path2(env, data->acvec[0]);
	data->fd4 = open("temp_file", O_CREAT | O_RDWR, 0777);
	if (data->path == NULL)
	{
		ft_printf("command not found: %s\n", data->acvec[0]);
		unlink("temp_file");
		exit (1);
	}
	if (data->i == 4 && check_file_name(data, av))
		dup2(data->fd3, STDIN_FILENO);
	else
		dup2(data->fd4, STDIN_FILENO);
	if (!av[data->i + 1])
		dup2(fd[1], STDOUT_FILENO);
	else
		dup2(data->fd4, STDOUT_FILENO);
	if (execve(data->path, data->acvec, env) == -1)
		perror("Error");
}

void	executing_pipe2(int *fd, char **av, char **env, t_pipex *data)
{
	close(fd[1]);
	data->fd6 = open(av[ft_amount(av)], O_WRONLY | O_CREAT | O_TRUNC);
	data->acvec = ft_split(av[data->i - 2], ' ');
	data->path = check_path2(env, data->acvec[0]);
	if (data->path == NULL)
	{
		ft_printf("command not found: %s \n", data->acvec[0]);
		unlink("temp_file");
		exit (1);
	}
	dup2(fd[0], STDIN_FILENO);
	dup2(data->fd6, STDOUT_FILENO);
	unlink("temp_file");
	if (execve(data->path, data->acvec, env) == -1)
	{
		perror("Error");
	}
}

int	main(int ac, char **av, char **env)
{
	int		fd[2];
	t_pipex	*data;

	if (ac >= 5)
	{
		data = malloc(sizeof(t_pipex));
		if (!data)
			return (0);
		env = get_path(env, data, fd, av);
		while (av[data->i])
		{
			if (data->id == 0)
				executing_pipe(fd, av, env, data);
			data->i += 1;
			wait(NULL);
			if (av[data->i])
				data->id = fork();
		}
		data->id = fork();
		if (data->id == 0)
			executing_pipe2(fd, av, env, data);
		free_all2(env, data);
	}
	else
		return (write(2, "Wrong number of arguments", 25), 0);
}
