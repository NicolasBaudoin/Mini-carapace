/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uuenkhba <uuenkhba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 02:05:11 by uuenkhba          #+#    #+#             */
/*   Updated: 2026/03/31 22:52:57 by uuenkhba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_FD_H
# define FT_PRINTF_FD_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "libft.h"

// put
void	ft_putchar_fd(int fd, char c, int *count);
void	ft_putstr_fd(int fd, char *s, int *count);
void	ft_putstr_fd2(char *s, int fd);
void	ft_putaddr_fd(int fd, size_t v, int prefix, int *count);
void	ft_putnbr_fd(int fd, long int nb, int *count);
void	ft_putchar_fd2(char c, int fd);
void	ft_putnbr_fd2(int n, int fd);
void	ft_putunbr_fd(int fd, unsigned int nb, int *count);
void	ft_putnbrhexa_fd(int fd, unsigned int v, int in_lowercase, int *count);
void	ft_putendl_fd(char *s, int fd);

// utils
int		printf_ft_startwith_fd(const char *s, const char *val);
int		ft_strcmp_fd(const char *s1, const char *s2);
size_t	ft_strlen_fd(const char *s);

// printf / dprintf
int		ft_printf_fd(const char *s, ...);
int		ft_dprintf_fd(int fd, const char *s, ...);

#endif
