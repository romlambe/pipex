/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romlambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 12:13:47 by romlambe          #+#    #+#             */
/*   Updated: 2024/03/10 22:00:25 by romlambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*stack = NULL;
	int			valread;

	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (free(stack), stack = NULL, NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	valread = 1;
	while (valread > 0)
	{
		valread = read(fd, buffer, BUFFER_SIZE);
		buffer[valread] = '\0';
		stack = ft_strjoin_gnl(stack, buffer);
		if (ft_strchr_gnl(stack))
			break ;
	}
	free (buffer);
	return (to_write (&stack));
}
