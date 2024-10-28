/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:05:54 by ipuig-pa          #+#    #+#             */
/*   Updated: 2024/10/28 17:38:37 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <limits.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

size_t	len(char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	newline(char *str);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_strchr(const char *s, int c);

char	*get_next_line(int fd);
char	*line_from_leftover(char *left, size_t line_len, size_t add);
char	*new_left(char *left, size_t line_len, size_t left_len, char *line);
char	*add_chunk(char *left, char *buffer, size_t bytes_read);
char	*free_leftover(char *left);
#endif