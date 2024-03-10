/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romlambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 16:09:40 by romlambe          #+#    #+#             */
/*   Updated: 2024/03/10 18:27:46 by romlambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#include "../libft/libft.h"

int main(int ac, char **av, char **env);
void child_process(char **av, char **env, int *fd);
void parent_process(char **av, char **env, int *fd);

char *find_path(char *cmd, char **env);
void	ft_execute(char *av, char **env);

