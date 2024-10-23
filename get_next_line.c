/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:04:00 by ipuig-pa          #+#    #+#             */
/*   Updated: 2024/10/23 15:47:31 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
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
		return (0);
	if (dstsize != 0)
	{
		while (i < dstsize - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen((char *)src));
}

size_t	newline_len(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	i = 0;
	if (!dst || !src)
		return (0);
	dst_len = ft_strlen(dst);
	src_len = ft_strlen((char *)src);
	if (dstsize == 0)
		return (src_len);
	if (dstsize <= dst_len)
		return (src_len + dstsize);
	while (i < dstsize - dst_len - 1 && src[i] != '\0')
	{
		dst[i + dst_len] = src[i];
		i++;
	}
	dst[i + dst_len] = '\0';
	return (dst_len + ft_strlen((char *)src));
}

char	*new_leftover(char *leftover, size_t line_len, size_t leftover_len)
{
	char	*temp;

	temp = (char *)malloc(leftover_len - line_len + 1);
	if (!temp)
		return (NULL);
	ft_strlcpy(temp, (leftover + line_len), (leftover_len - line_len));
	return (temp);
}

char	*line_from_leftover(char *leftover, size_t line_len, size_t leftover_len)
{
	char	*line;

	line = (char *)malloc(line_len + 1);
	if (!line)
		return (NULL);
	ft_strlcpy(line, leftover, line_len + 1);
	return (line);
}

char	*add_chunk(char *leftover, char *buffer, size_t bytes_read, size_t leftover_len)
{
	char		*temp;

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
	char		buffer[BUFFER_SIZE];
	size_t		bytes_read;
	static char	*leftover;
	size_t		line_len;
	size_t		leftover_len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	leftover_len = ft_strlen(leftover);
	line_len = newline_len(leftover);
	while (!(line_len < leftover_len))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read > 0)
			leftover = add_chunk(leftover, buffer, bytes_read, leftover_len);
		else if (bytes_read == 0)
			return(leftover);
		else
			return (NULL);
		line_len = newline_len(leftover);
		leftover_len = ft_strlen(leftover);
	}
	line = line_from_leftover(leftover, line_len, leftover_len);
	leftover = new_leftover(leftover, line_len, leftover_len);
	return (line);
}


/*


		if (line_len <= leftover_len)
		{
			line = (char *)malloc(line_len + 1);
			if (!line)
				return (NULL);
			ft_strlcpy(line, leftover, line_len + 1);
			temp = (char *)malloc(leftover_len - line_len + 1);
			if (!temp)
				return (NULL);
			ft_strlcpy(temp, (leftover + line_len), (leftover_len - line_len));
			free(leftover);
			leftover = (char *)malloc(leftover_len - line_len + 1);
			if (!leftover)
				return (NULL);
			ft_strlcpy(leftover, temp, leftover_len - line_len + 1);
			free(temp);
			return (line);
		}
	
	return (process_leftover);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read > 0)
	{
		temp = (char *)malloc(bytes_read + leftover_len + 1);
		if (!temp)
			return (NULL);
		if (leftover)
		{
			ft_strlcpy(temp, leftover, leftover_len + 1);
			free(leftover);
		}
		ft_strlcat(temp, buffer, bytes_read + leftover_len + 1);
		leftover = (char *)malloc(bytes_read + leftover_len + 1);
		if (!leftover)
			return (NULL);
		ft_strlcpy(leftover, temp, bytes_read + leftover_len + 1);
		free(temp);
		return (process_leftover());
	}
	return (NULL);
}
*/