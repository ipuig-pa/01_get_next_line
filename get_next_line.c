/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:04:00 by ipuig-pa          #+#    #+#             */
/*   Updated: 2024/10/23 12:56:37 by ipuig-pa         ###   ########.fr       */
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

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	i = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
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
	return (dst_len + ft_strlen(src));
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE];
	static char	*leftover;
	size_t		bytes_read;
	size_t		line_len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	leftover_len = str_len(leftover);
	if (leftover)
	{
		line_len = newline_len(leftover);
		if (line_len <= leftover_len)
		{
			line = (char *)malloc(line_len + 1);
			if (!line)
				return (NULL);
			strlcpy(line, leftover, line_len + 1);
			temp = (char*)malloc(leftover_len - line_len + 1);
			if (!temp)
				return (NULL);
			strlcpy(temp, (leftover + line_len), (leftover_len - line_len));
			free(leftover);
			leftover = (char*)malloc(leftover_len - line_len + 1);
			if (!leftover)
				return (NULL);
			strlcpy(leftover, temp, leftover_len -line_len + 1);
			free(temp);
			return(line);
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
		if (leftover)
			free(leftover);
		leftover = (char*)malloc(bytes_read + leftover_len + 1);
		if (!leftover)
			return (NULL);
		strlcpy(leftover, temp, bytes_read + leftover_len + 1);
		free(temp);
		return (get_next_line(fd));
	}
}