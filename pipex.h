/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romlambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 16:09:40 by romlambe          #+#    #+#             */
/*   Updated: 2024/03/11 13:45:14 by romlambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#include "../libft/libft.h"
// #include "../gnl/get_next_line.h"


// pipex
char	*find_path(char *cmd, char **env);
void	ft_execute(char *av, char **env);
void	handle_error(void);

// pipex bonus


