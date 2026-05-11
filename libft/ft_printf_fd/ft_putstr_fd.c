/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uuenkhba <uuenkhba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 02:02:52 by uuenkhba          #+#    #+#             */
/*   Updated: 2026/03/13 16:23:49 by uuenkhba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd.h"

void	ft_putstr_fd(int fd, char *s, int *count)
{
	int	s_length;
	int	length;

	if (!s)
	{
		ft_putstr_fd(fd, "(null)", count);
		return ;
	}
	s_length = ft_strlen_fd(s);
	length = write(fd, s, s_length);
	if (length > 0)
		*count += length;
}
