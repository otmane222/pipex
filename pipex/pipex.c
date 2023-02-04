/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboulgh <oaboulgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 14:32:56 by oaboulgh          #+#    #+#             */
/*   Updated: 2023/02/03 16:41:24 by oaboulgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h" 

char	*check_path(char **paths, char *path)
{
	int		i;

	i = 0;
	if (access(path, X_OK) == 0)
		return (path);
	path = ft_strjoin("/", path);
	while (paths[i])
	{
		paths[i] = ft_strjoin(paths[i], path);
		if (access(paths[i], X_OK) == 0)
			return (paths[i]);
		i++;
	}
	return (NULL);
}

char	**get_env(char **env, t_pipex *data, int *fd)
{
	int		i;
	char	*str;
	char	**rtn;

	i = 0;
	pipe(fd);
	data->id = fork();
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
		return (rtn);
	}
	return (NULL);
}

void	exucitng_in_pipe(int *fd, char **av, t_pipex *data, char **env)
{
	close(fd[0]);
	data->avvec = ft_split(av[2], ' ');
	data->path = check_path(env, data->avvec[0]);
	data->fd3 = open(av[1], O_RDWR, 0777);
	if (data->fd3 == -1)
	{
		ft_putstr2(2, "No such file or directory: ");
		write (2, av[1], ft_strlen(av[1]));
		write(2, "\n", 1);
		exit (1);
	}
	if (data->path == NULL)
	{
		write(2, "Command not found: ", 19);
		write(2, data->avvec[0], ft_strlen(data->avvec[0]));
		write(2, "\n", 1);
		exit (1);
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
	data->path = check_path(env, data->avvec[0]);
	if (data->path == NULL)
	{
		dup2(STDIN_FILENO, STDERR_FILENO);
		write(2, "Command not found: ", 19);
		write(2, data->avvec[0], ft_strlen(data->avvec[0]));
		write(2, "\n", 1);
		exit (1);
	}
	if (dup2(fd[0], STDIN_FILENO) == -1)
		perror("Error");
	if (dup2(data->fd4, STDOUT_FILENO) == -1)
		perror("Error");
	if (execve(data->path, data->avvec, NULL) == -1)
	{
		perror("Error");
		exit (1);
	}
}

int	main(int ac, char **av, char **env)
{
	t_pipex	*data;
	int		fd[2];

	data = malloc(sizeof(t_pipex));
	if (!data)
		return (0);
	if (ac == 5)
	{
		env = get_env(env, data, fd);
		if (env == NULL)
			perror ("PATH coudn't found");
		if (data->id == 0)
			exucitng_in_pipe(fd, av, data, env);
		else
		{
			data->id = fork();
			if (data->id == 0)
				exucitng_in_pipe2(fd, av, data, env);
		}
		free_all2(env, data);
		wait(NULL);
	}
	else
		return (write(2, "Wrong number of arguments", 25), 0);
}
