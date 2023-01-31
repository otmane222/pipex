/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboulgh <oaboulgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 14:32:56 by oaboulgh          #+#    #+#             */
/*   Updated: 2023/01/31 03:01:24 by oaboulgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h" 

char	*check_path(char **paths, char *path)
{
	int		i;

	i = 0;
	while (paths[i])
	{
		paths[i] = ft_strjoin(paths[i], path);
		if (access(paths[i], R_OK) == 0)
			return (paths[i]);
		i++;
	}
	return (NULL);
}

char	**get_env(char **env)
{
	int		i;
	char	*str;
	char	**rtn;

	i = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH", 5))
			break ;
		i++;
	}
	if (env[i])
	{
		str = env[i] + 5;
		rtn = ft_split(str, ':');
		free(rtn[6]);
		rtn[6] = NULL;
		return (rtn);
	}
	return (NULL);
}

void	exucitng_in_pipe(int *fd, char **av, t_pipex *data, char **env)
{
	close(fd[0]);
	data->avvec = ft_split(av[2], ' ');
	data->avvec[0] = ft_strjoin("/", data->avvec[0]);
	data->path = check_path(env, data->avvec[0]);
	data->fd3 = open(av[1], O_RDWR, 0777);
	if (data->path == NULL)
	{
		write(1, "zsh: command not found: ", 24);
		write(1, data->avvec[0] + 1, ft_strlen(data->avvec[0]) - 1);
		write(1, "\n", 1);
		exit (0);
	}
	if (dup2(data->fd3, STDIN_FILENO) == -1)
		perror("Error");
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		perror("Error");
	if (execve(data->path, data->avvec, NULL) == -1)
		perror("Error");
}

void	exucitng_in_pipe2(int *fd, char **av, t_pipex *data, char **env)
{
	close(fd[1]);
	data->fd4 = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 0777);
	data->avvec = ft_split(av[3], ' ');
	data->avvec[0] = ft_strjoin("/", data->avvec[0]);
	data->path = check_path(env, data->avvec[0]);
	if (data->path == NULL)
	{
		dup2(STDIN_FILENO, STDERR_FILENO);
		write(1, "zsh: command not found: ", 24);
		write(1, data->avvec[0] + 1, ft_strlen(data->avvec[0]) - 1);
		write(1, "\n", 1);
		exit (0);
	}
	if (dup2(fd[0], STDIN_FILENO) == -1)
		perror("Error");
	if (dup2(data->fd4, STDOUT_FILENO) == -1)
		perror("Error");
	if (execve(data->path, data->avvec, NULL) == -1)
	{
		perror("Error");
		exit (0);
	}
}

int	main(int ac, char **av, char **env)
{
	t_pipex	*data;
	int		id;
	int		fd[2];

	data = malloc(sizeof(t_pipex));
	if (!data)
		return (perror("Allocating error :"), 0);
	if (ac == 5)
	{
		pipe(fd);
		id = fork();
		env = get_env(env);
		if (id == 0)
			exucitng_in_pipe(fd, av, data, env);
		else
		{
			id = fork();
			if (id == 0)
				exucitng_in_pipe2(fd, av, data, env);
		}
		wait(NULL);
	}
	else
		return (0);
}
