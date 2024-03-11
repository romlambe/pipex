/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romlambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:15:02 by romlambe          #+#    #+#             */
/*   Updated: 2024/03/11 23:29:37 by romlambe         ###   ########.fr       */
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
			filein = open_file(av[ac - 1], 0);
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
}
void	process(char *av, char **env)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		// handle_error();
		return (perror("erreur pipe process"));
	pid = fork();
	if (pid == -1)
		// handle_error();
		return (perror("erreur pid process"));
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
	char	*line;

	if (ac < 6)
		handle_error();
	if (pipe(fd) == -1)
		handle_error();
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		while(1)
		{
			line = get_next_line(0);
			if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
			{
				exit(EXIT_SUCCESS);
			}
			write(fd[1], line, ft_strlen(line));
			free(line);
		}
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		wait(NULL);
	}
}

int	open_file(char *av, int i)
{
	int	file;

	if (i == 0)
		file = open(av, O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (i == 1)
		file = open(av, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (i == 2)
		file = open(av, O_RDONLY, 0777);
	if (file == -1)
		handle_error();
	return (file);
}
