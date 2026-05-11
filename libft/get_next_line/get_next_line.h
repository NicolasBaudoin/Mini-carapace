/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uuenkhba <uuenkhba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 12:26:34 by uuenkhba          #+#    #+#             */
/*   Updated: 2026/03/13 17:29:51 by uuenkhba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
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
char	*get_next_line(int fd);

#endif
