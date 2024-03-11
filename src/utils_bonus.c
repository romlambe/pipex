/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romlambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:15:01 by romlambe          #+#    #+#             */
/*   Updated: 2024/03/11 18:52:16 by romlambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*find_path(char *cmd, char **env)
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
		while (cmd[++i])
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

void	handle_error(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}

