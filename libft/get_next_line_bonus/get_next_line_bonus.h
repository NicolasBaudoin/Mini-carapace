/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 21:48:44 by uuenkhba          #+#    #+#             */
/*   Updated: 2026/03/23 12:09:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include "libft.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

size_t	ft_strlen_gb(char *s);
char	*ft_strjoin_gb(char *str1, char const *s2);
char	*ft_strchr_gb(char *s, int c);
char	*ft_substr_gb(char *str, unsigned int start, size_t len);
char	*get_next_line_b(int fd);
char	*ft_free_s(char **str);
char	*clean_storage(char *storage);
char	*new_line(char *storage);
char	*readbuf(int fd, char *storage);

#endif
