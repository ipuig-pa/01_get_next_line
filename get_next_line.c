/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:04:00 by ipuig-pa          #+#    #+#             */
/*   Updated: 2024/10/21 17:31:17 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	str_len(char *str)
{
	size_t	len;

	while (str)
	{
		str++;
		len++;
	}
	return (len);
}

char	*str_copy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	if (dst && src)
	{
		while (i < str_len(dst) - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (dst);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE];
	static char	*leftover;
	char		*line;
	size_t		bytes_read;
	size_t		i;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	leftover = NULL;
	leftover_len = 0;
	while (bytes_read > 0)
	{
		i = 0;
		while (i <= bytes_read && buffer[i] != '\n')
			i++;
		if (buffer[i] == '\n')
		{
			if (leftover)
				return ((char *)malloc(ft_strlen(leftover) + i));
			free(leftover);
			leftover = NULL;
		}
		else
			if (leftover)
			{
				leftover_cpy = str_copy(leftover_cpy, leftover);
				free(leftover);
				leftover =(static char *)malloc(BUFFER_SIZE + leftover_len);
				if (!leftover)
					return (NULL);
				str_copy(leftover, leftover_cpy);
				strlcat(leftover, buffer, BUFFER_SIZE);
			}
			else
			{
				leftover =(static char *)malloc(BUFFER_SIZE);
				if (!leftover)
					return (NULL);
				i = 0;
				while (i <= BUFFER_SIZE)
				{
					leftover[i] = buffer[i]
					i++;
				}
			}
			bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (bytes_read == -1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
