/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:04:00 by ipuig-pa          #+#    #+#             */
/*   Updated: 2024/10/22 13:24:42 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	str_len(char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] != '\0')
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!dst || !src)
		return (dst);
	if (dstsize != 0)
	{
		while (i < dstsize - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

size_t	newline_len(char *str);
{
	size_t	i; 

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\0')
		i++;
	return(i);
}

char	*line_in_leftover(char *leftover, size_t line_len)
{
	char	*line;
	char	*temp;

	line = (char *)malloc(newline_len + 1);
	if (!line)
		return (NULL);
	strlcpy(line, leftover, line_len + 1);
	temp = (char*)malloc(leftover_len - line_len + 1);
	if (!temp)
		return (NULL);
	strlcpy(temp, leftover, el que queda despres de n);
	free(leftover);
	leftover = (char*)malloc(leftover_len - line_len + 1);
	if (!leftover)
		return (NULL);
	strlcpy(leftover, temp, bytes_read + leftover_len + 1);
	//manage new leftover
	return(line);
}

keep_reading()
{
	bytes_read = read(fd, buffer, BUFFER_SIZE);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE];
	static char	*leftover;
	size_t		bytes_read;
	size_t		line_len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (leftover)
	{
		line_len = newline_len(leftover);
		leftover_len = strlen(leftover);
		if (line_len <= leftover_len)
		{
			line = (char *)malloc(newline_len + 1);
			if (!line)
				return (NULL);
			strlcpy(line, leftover, line_len + 1);
			
			//manage new leftover
			return(line);
		}
		else
		{
			bytes_read = read(fd, buffer, BUFFER_SIZE);
			if (bytes_read > 0)
			{
				temp = (char*)malloc(bytes_read + leftover_len + 1);
				if (!temp)
					return (NULL);
				strlcpy(temp, buffer, bytes_read + 1);
				strlcat(temp, leftover);
				free(leftover);
				leftover = (char*)malloc(bytes_read + leftover_len + 1);
				if (!leftover)
					return (NULL);
				strlcpy(leftover, temp, bytes_read + leftover_len + 1);
				return (get_next_line(fd));
			}
		}
	}
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read > 0)
	{
		temp = (char*)malloc(bytes_read + leftover_len + 1);
		if (!temp)
			return (NULL);
		strlcpy(temp, buffer, bytes_read + 1);
		strlcat(temp, leftover);
		free(leftover);
		leftover = (char*)malloc(bytes_read + leftover_len + 1);
		if (!leftover)
			return (NULL);
		strlcpy(leftover, temp, bytes_read + leftover_len + 1);
		return (get_next_line(fd));
	}
}
				






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
			}
	
	
	
	bytes_read = read(fd, buffer, BUFFER_SIZE);
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
					leftover[i] = buffer[i];
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
