/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:04:00 by ipuig-pa          #+#    #+#             */
/*   Updated: 2024/10/28 17:35:25 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	size_t		bytes_read;
	static char	*left[OPEN_MAX];
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (left[fd] = free_leftover(left[fd]));
	if (left[fd] && ft_strchr(left[fd], '\n'))
	{
		line = line_from_leftover(left[fd], newline(left[fd]), 2);
		left[fd] = new_left(left[fd], newline(left[fd]), len(left[fd]), line);
		return (line);
	}
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		left[fd] = add_chunk(left[fd], buffer, bytes_read);
		return (get_next_line(fd));
	}
	if (bytes_read == 0 && left[fd] && *left[fd])
		line = line_from_leftover(left[fd], len(left[fd]), 1);
	left[fd] = free_leftover(left[fd]);
	return (line);
}

char	*line_from_leftover(char *left, size_t line_len, size_t add)
{
	char	*line;

	line = (char *)malloc(line_len + add);
	if (!line)
		return (NULL);
	ft_strlcpy(line, left, line_len + add);
	return (line);
}

char	*new_left(char *left, size_t line_len, size_t left_len, char *line)
{
	char	*temp;

	if (!line)
		return (free_leftover(left));
	if (line_len >= left_len - 1)
	{
		free(left);
		return (NULL);
	}
	temp = (char *)malloc(left_len - line_len);
	if (!temp)
	{
		free(left);
		return (NULL);
	}
	ft_strlcpy(temp, (left + line_len + 1), (left_len - line_len));
	free(left);
	return (temp);
}

char	*add_chunk(char *left, char *buffer, size_t bytes_read)
{
	char	*temp;
	size_t	leftover_len;

	leftover_len = len(left);
	temp = (char *)malloc(bytes_read + leftover_len + 1);
	if (!temp)
	{
		free(left);
		return (NULL);
	}
	if (left)
	{
		ft_strlcpy(temp, left, leftover_len + 1);
		free(left);
		ft_strlcat(temp, buffer, bytes_read + leftover_len + 1);
	}
	else
		ft_strlcpy(temp, buffer, bytes_read + 1);
	return (temp);
}

char	*free_leftover(char *left)
{
	if (left)
	{
		free(left);
		left = NULL;
	}
	return (left);
}

/*#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("prova.txt", 0);
 	line = get_next_line(fd);
	printf("%s", line);
	while ((line = get_next_line(fd)))
	{
		printf("LINE_READ: %s", line);
		free(line);
	}
	 printf("from standard input:");
	while ((line = get_next_line(0)))
	{
		printf("LINE_READ: %s", line);
		free(line);
	} 
	return (0);
}*/