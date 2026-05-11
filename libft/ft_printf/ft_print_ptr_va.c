/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr_va.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uuenkhba <uuenkhba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:49:09 by uuenkhba          #+#    #+#             */
/*   Updated: 2026/03/24 16:10:25 by uuenkhba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hex_ptr(unsigned long addr)
{
	char	buffer[32];
	int		i;
	int		result;

	if (addr == 0)
		return (write(1, "0", 1));
	i = 0;
	while (addr)
	{
		buffer[i] = BASE_HEX[addr % 16];
		addr /= 16;
		i++;
	}
	result = i;
	while (i--)
		write(1, &buffer[i], 1);
	return (result);
}

int	ft_print_ptr_va(va_list args)
{
	unsigned long	addr;
	int				len;

	addr = (unsigned long)va_arg(args, void *);
	if (addr == 0)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	len = ft_hex_ptr((unsigned long)addr);
	return (len + 2);
}
