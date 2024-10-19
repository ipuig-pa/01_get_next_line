/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:04:00 by ipuig-pa          #+#    #+#             */
/*   Updated: 2024/10/19 17:50:18 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//falta copiar de buffer al string de malloc. 
//falta entendre com anira agafant el que ja ha llegit. 

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE];
	static char	*leftover;
	char		*line;
	size_t		bytes_read;
	size_t		i;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	used_buffers = 0;
	leftover = //afegir el que queda del buffer no usat
	while (bytes_read > 0)
	{
		i = 0;
		while (i <= bytes_read && buffer[i] != '\n')
			i++;
		if (buffer[i] == '\n')
		{
			line = (char *)malloc(BUFFER_SIZE * used_buffers + i);
			if (!line)
				return (NULL);
		}
		else
			bytes_read = read(fd, buffer, BUFFER_SIZE);
		used_buffers++;
	}
	if (bytes_read == -1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
