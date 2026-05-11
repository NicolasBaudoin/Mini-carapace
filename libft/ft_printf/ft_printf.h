/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uuenkhba <uuenkhba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:20:16 by uuenkhba          #+#    #+#             */
/*   Updated: 2026/03/24 23:03:29 by uuenkhba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "libft.h"
# define BASE_HEX "0123456789abcdef"
# define BASE_HEX_UP "0123456789ABCDEF"

int		ft_printf(const char *format, ...);
int		ft_print_char(int c);
int		ft_print_str(char *s);
int		ft_print_ptr(void *p);
int		ft_print_nbr(long n);
int		ft_print_unsigned(unsigned int n);
int		ft_print_hex(unsigned long n, char format); // 'x' or 'X'
int		ft_putnbr_base_count(unsigned long n, char *base);
int		f_strlen(const char *s);
void	ft_putstr(char *s);
int		ft_print_dec_va(va_list args);
int		ft_print_hex_low_va(va_list args);
int		ft_print_hex_up(va_list args);
int		ft_print_int_va(va_list args);
int		ft_print_percent(va_list args);
int		ft_print_char_va(va_list args);
int		ft_print_string(va_list args);
int		ft_print_ptr_va(va_list args);
int		ft_printf_va(const char *s, ...);

#endif
