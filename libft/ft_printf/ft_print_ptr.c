/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uuenkhba <uuenkhba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:49:09 by uuenkhba          #+#    #+#             */
/*   Updated: 2026/03/24 23:02:18 by uuenkhba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(void *p)
{
	if (!p)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	return (2 + ft_putnbr_base_count((unsigned long)p, "0123456789abcdef"));
}
