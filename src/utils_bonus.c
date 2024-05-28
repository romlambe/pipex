/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romlambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:15:01 by romlambe          #+#    #+#             */
/*   Updated: 2024/05/28 22:45:58 by romlambe         ###   ########.fr       */
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
		handle_error();
	}
	if (execve(path, cmd, env) == -1)
		handle_error();
}

void	handle_error(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}

int	ft_strncmp_limiter(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	while (i < n && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (i == n && s1[i] == '\n' && s1[i + 1] == '\0')
		return (0);
	else
		return (1);
}
