/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:04:00 by ipuig-pa          #+#    #+#             */
/*   Updated: 2024/10/24 10:48:26 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*new_leftover(char *leftover, size_t line_len, size_t leftover_len)
{
	char	*temp;

	if (line_len >= leftover_len)
	{
		free(leftover);
		return (NULL);
	}
	temp = (char *)malloc(leftover_len - line_len + 1);
	if (!temp)
	{
		free(leftover);
		return (NULL);
	}
	ft_strlcpy(temp, (leftover + line_len), (leftover_len - line_len));
	free(leftover);
	return (temp);
}

char	*line_from_leftover(char *leftover, size_t line_len)
{
	char	*line;
	size_t	leftover_len;

	leftover_len = ft_strlen(leftover);
	if (!leftover || line_len == 0)
		return (NULL);
	line = (char *)malloc(line_len + 1);
	if (!line)
	{
		free(leftover);
		return (NULL);
	}
	ft_strlcpy(line, leftover, line_len + 1);
	return (line);
}

char	*add_chunk(char *leftover, char *buffer, size_t bytes_read)
{
	char	*temp;
	size_t	leftover_len;

	leftover_len = ft_strlen(leftover);
	temp = (char *)malloc(bytes_read + leftover_len + 1);
	if (!temp)
		return (NULL);
	if (leftover)
	{
		ft_strlcpy(temp, leftover, leftover_len + 1);
		free(leftover);
		ft_strlcat(temp, buffer, bytes_read + leftover_len + 1);
	}
	else
		ft_strlcpy(temp, buffer, bytes_read + 1);
	return (temp);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	size_t		bytes_read;
	static char	*leftover;
	size_t		line_len;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line_len = newline_len(leftover);
	if (line_len < ft_strlen(leftover))
	{
		line = line_from_leftover(leftover, line_len);
		leftover = new_leftover(leftover, line_len, ft_strlen(leftover));
		return (line);
	}
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		leftover = add_chunk(leftover, buffer, bytes_read);
		if (!leftover)
			return (NULL);
		line_len = newline_len(leftover);
		if (line_len < ft_strlen(leftover))
		{
			line = line_from_leftover(leftover, line_len);
			leftover = new_leftover(leftover, line_len, ft_strlen(leftover));
			return (line);
		}
	}
	if (bytes_read == 0 && leftover && *leftover)
	{
		line = line_from_leftover(leftover, ft_strlen(leftover));
		free (leftover);
		leftover = NULL;
		return (line);
	}
	if (leftover)
		free(leftover);
	leftover = NULL;
	return (NULL);
}
