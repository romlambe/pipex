/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romlambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 16:09:40 by romlambe          #+#    #+#             */
/*   Updated: 2024/05/28 22:46:49 by romlambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#include "libft/libft.h"
#include "get_next_line/get_next_line.h"


// pipex
char	*find_path(char *cmd, char **env);
void	ft_execute(char *av, char **env);
void	handle_error(void);

// pipex bonus

int		open_file(char *av, int i);
void	process(char *av, char **env);
void	here_doc(char *limiter, int ac);
void	here_doc_2(char *limiter, int *fd);
int		ft_strncmp_limiter(const char *s1, const char *s2, size_t n);
