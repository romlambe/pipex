/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romlambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:15:02 by romlambe          #+#    #+#             */
/*   Updated: 2024/03/13 22:44:16 by romlambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(int ac, char **av, char **env)
{
	int	i;
	int	filein;
	int	fileout;

	if (ac >= 5)
	{
		if (ft_strncmp(av[1], "here_doc", 8) == 0)
		{
			i = 3;
			fileout = open_file(av[ac - 1], 0);
			here_doc(av[2], ac);
		}
		else
		{
			i = 2;
			fileout = open_file(av[ac - 1], 1);
			filein = open_file(av[1], 2);
			dup2(filein, STDIN_FILENO);
		}
		while (i < ac - 2)
			process(av[i++], env);
		dup2(fileout, STDOUT_FILENO);
		ft_execute(av[ac - 2], env);
	}
	handle_error();
}

void	process(char *av, char **env)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		handle_error();
	pid = fork();
	if (pid == -1)
		handle_error();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		ft_execute(av, env);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		wait(NULL);
	}
}

void	here_doc(char *limiter, int ac)
{
	pid_t	pid;
	int		fd[2];

	if (ac < 6)
		handle_error();
	if (pipe(fd) == -1)
		handle_error();
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		while (1)
			here_doc_2(limiter, fd);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		wait(NULL);
	}
}

void	here_doc_2(char *limiter, int *fd)
{
	char	*line;

	line = get_next_line(0);
	if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
		exit(EXIT_SUCCESS);
	ft_putstr_fd(line, fd[1]);
	free(line);
}

int	open_file(char *av, int i)
{
	int	file;

	file = -1;
	if (i == 0)
		file = open(av, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else if (i == 1)
		file = open(av, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (i == 2)
		file = open(av, O_RDONLY, 0644);
	if (file == -1)
		handle_error();
	return (file);
}

//test
