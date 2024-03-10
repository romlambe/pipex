/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romlambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 16:09:15 by romlambe          #+#    #+#             */
/*   Updated: 2024/03/10 18:36:48 by romlambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(int ac, char **av, char **env)
{
	pid_t	pid;
	int		fd[2];

	if (ac == 5)
	{
		if (pipe(fd) == - 1)
		{
			perror("Error pipe");
			exit(EXIT_FAILURE);
		}
		pid = fork();
		if (pid == -1)
		{
			perror("Error fork");
			exit(EXIT_FAILURE);
		}
		if (pid == 0)
		{
			child_process(av, env, fd);
		}
		waitpid(pid, NULL, 0);
		parent_process(av, env, fd);
	}
	else
	{
		perror("Error arguments");
		exit(EXIT_FAILURE);
	}
	return (0);
}

void child_process(char **av, char **env, int *fd)
{
	int filein;


	filein = open(av[1], O_RDONLY , 0777);
	if (filein == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	dup2(fd[1], STDOUT_FILENO);
	dup2(filein, STDIN_FILENO);
	close(fd[0]);
	ft_execute(av[2], env);
}

void	parent_process(char **av, char **env, int *fd)
{
	int	fileout;
	fileout = open(av[4], O_WRONLY | O_CREAT | O_TRUNC , 0664);
	if (fileout == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	dup2(fd[0], STDIN_FILENO);
	dup2(fileout, STDOUT_FILENO);
	close(fd[1]);
	ft_execute(av[3], env);
}

//ft pour recuperer le path
char *find_path(char *cmd, char **env)
{
	char	**check_path;
	char	*path;
	char	*part_path;
	int		i;

	i = 0;
	while (ft_strnstr(env[i], "PATH", 4) == NULL)
		i++;
	check_path = ft_split(env[i] + 5, ':');
	i = -1;
	while (check_path[++i])
	{
		part_path = ft_strjoin(check_path[i], "/");
		path = ft_strjoin(part_path, cmd);
		free (part_path);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
	}
	i = -1;
	while (check_path[++i])
		free(check_path[i]);
	free(check_path);
	return (0);
}

void	ft_execute(char *av, char **env)
{
	char	**cmd;
	char	*path;
	int		i;

	i = -1;
	cmd = ft_split(av, ' ');
	path = find_path(cmd[0], env);
	if (path == NULL)
	{
		while(cmd[++i])
			free (cmd[i]);
		free (cmd);
		perror("Error execute cmd");
		exit(EXIT_FAILURE);
	}
	if (execve(path, cmd, env) == -1)
	{
		perror("Error execute");
		exit(EXIT_FAILURE);
	}
}


