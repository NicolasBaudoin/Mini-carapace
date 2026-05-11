/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_fd.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uuenkhba <uuenkhba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 12:26:34 by uuenkhba          #+#    #+#             */
/*   Updated: 2026/03/31 22:55:32 by uuenkhba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_FD_H
# define GET_NEXT_LINE_FD_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

char	*gnl_ft_strchr(char *s, char c);
size_t	gnl_ft_strlen(char *str);
void	gnl_ft_strcpy(char *dst, char *src);
char	*gnl_ft_strndup(char *str, size_t n);
char	*gnl_ft_strjoin(char *s1, char *s2);
char	*get_next_line_fd(int fd);

#endif
