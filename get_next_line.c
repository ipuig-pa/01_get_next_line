/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:04:00 by ipuig-pa          #+#    #+#             */
/*   Updated: 2024/10/24 15:40:12 by ipuig-pa         ###   ########.fr       */
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
	ft_strlcpy(temp, (leftover + line_len + 1), (leftover_len - line_len));
	free(leftover);
	return (temp);
}

char	*line_from_leftover(char *leftover, size_t line_len)
{
	char	*line;
	size_t	leftover_len;

	leftover_len = ft_strlen(leftover);
	//printf("leftover_len: %zu\n", leftover_len);
	if (!leftover)
		return (NULL);
	line = (char *)malloc(line_len + 2);
	if (!line)
	{
		free(leftover);
		return (NULL);
	}
	//printf("line: %s\n", line);
	ft_strlcpy(line, leftover, line_len + 2);
	//printf("line: %s\n", line);
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

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (leftover)
	{
		//printf("there was leftover\n");
		//printf("leftover: %s\n", leftover);
		line_len = newline_len(leftover);
		//printf("line_len: %zu\n", line_len);
		//printf("leftover_len: %zu\n", ft_strlen(leftover));
		if (line_len < ft_strlen(leftover))
		{
			//printf("there is a new line in leftover\n");
			line = line_from_leftover(leftover, line_len);
			//printf("line: %s\n", line);
			leftover = new_leftover(leftover, line_len, ft_strlen(leftover));
			//printf("newleftover: %s\n", leftover);
			return (line);
		}
	}
	//printf("No leftover\n");
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		//printf("bytes_read: %zu\n", bytes_read);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		//printf("buffer: %s\n", buffer);
		leftover = add_chunk(leftover, buffer, bytes_read);
		//printf("leftover: %s\n", leftover);
		if (!leftover)
			return (NULL);
		line_len = newline_len(leftover);
		//printf("line_len: %zu\n", line_len);
		//printf("leftover_len: %zu\n", ft_strlen(leftover));
		if (line_len < ft_strlen(leftover))
		{
			line = line_from_leftover(leftover, line_len);
			//printf("line: %s\n", line);
			leftover = new_leftover(leftover, line_len, ft_strlen(leftover));
			//printf("newleftover: %s\n", leftover);
			return (line);
		}
	}
	if (bytes_read == 0 && leftover && *leftover)
	{
		//printf("leftover_len: %zu\n", ft_strlen(leftover));
		line = line_from_leftover(leftover, ft_strlen(leftover));
		//printf("line: %s\n", line);
		free (leftover);
		leftover = NULL;
		return (line);
	}
	if (leftover)
		free(leftover);
	leftover = NULL;
	return (NULL);
}

/*#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("prova.txt", 0);
	while ((line = get_next_line(fd)))
	{
		printf("LINE_READ: %s\n", line);
		free(line);
	}
	return (0);
}*/
