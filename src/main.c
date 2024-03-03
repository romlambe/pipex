/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romlambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 16:09:15 by romlambe          #+#    #+#             */
/*   Updated: 2024/03/03 16:59:17 by romlambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int main()
{
	printf("hello");
	return 0;
}

// int	main (int ac, char **av)
// {
// 	pid_t	pid;
// 	int		fd[2];

// 	if (ac != 5)
// 	{
// 		perror("trop d'arguments");
// 		exit(EXIT_FAILURE);
// 	}
// 	if (pipe(fd) == - 1)
// 	{
// 		perror("pipe");
// 		exit(EXIT_FAILURE);
// 	}
// 	pid = fork();
// 	if (pid == -1)
// 	{
// 		perror("fork");
// 		exit(EXIT_FAILURE);
// 	}
// 	if (pid == 0)
// 	{
// 		close(fd[0]);
// 		printf("Hello parents");
// 		close (fd[1]);
// 		exit(EXIT_SUCCESS);
// 	}
// 	else
// 	{
// 		close(fd[1]);
// 		printf("From child");
// 		wait(NULL);
// 		close(fd[0]);
// 		exit(EXIT_SUCCESS);
// 	}
// 	return 0;
// }
