/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:05:54 by ipuig-pa          #+#    #+#             */
/*   Updated: 2024/10/24 16:57:25 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
//# define BUFFER_SIZE 1024
size_t	ft_strlen(char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	newline_len(char *str);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*new_leftover(char *leftover, size_t line_len, size_t leftover_len);
char	*line_from_leftover(char *leftover, size_t line_len);
char	*add_chunk(char *leftover, char *buffer, size_t bytes_read);
char	*get_next_line(int fd);
int		ft_strchr(const char *s, int c);
#endif