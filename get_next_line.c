/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:04:00 by ipuig-pa          #+#    #+#             */
/*   Updated: 2024/10/19 12:45:54 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE];
	size_t	bytes_read;
	size_t	line_length;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE)
		line_length = 0;
		while (line_length <= bytes_read && buffer[i] != '\n')
			line_length++;
		//tenir en compte que potser encara no ha arribat al final de la linia
		malloc(line_length);
		copiar de buffer al string de malloc. 
	}
	if (bytes_read == -1)
	{

	}
}