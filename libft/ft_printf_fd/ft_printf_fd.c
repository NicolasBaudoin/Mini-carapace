/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uuenkhba <uuenkhba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 02:02:04 by uuenkhba          #+#    #+#             */
/*   Updated: 2026/03/13 17:23:45 by uuenkhba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd.h"

static const char	*get_format(const char *s)
{
	const char	*formats[] = {"%c", "%s", "%p", "%d", "%i", "%u", "%x", "%X",
		"%%", NULL};
	size_t		i;

	if (*s == '%')
	{
		i = 0;
		while (formats[i])
		{
			if (printf_ft_startwith_fd(s, formats[i]))
				return (formats[i]);
			i++;
		}
	}
	return (NULL);
}

static void	handle_format(va_list *args, int fd, const char *format, int *count)
{
	if (!ft_strcmp_fd("%c", format))
		ft_putchar_fd(fd, va_arg(*args, int), count);
	else if (!ft_strcmp_fd("%s", format))
		ft_putstr_fd(fd, (char *)va_arg(*args, char *), count);
	else if (!ft_strcmp_fd("%p", format))
		ft_putaddr_fd(fd, (size_t)va_arg(*args, void *), 1, count);
	else if (!ft_strcmp_fd("%d", format))
		ft_putnbr_fd(fd, (int)va_arg(*args, int), count);
	else if (!ft_strcmp_fd("%i", format))
		ft_putnbr_fd(fd, (int)va_arg(*args, int), count);
	else if (!ft_strcmp_fd("%u", format))
		ft_putunbr_fd(fd, (unsigned int)va_arg(*args, unsigned int), count);
	else if (!ft_strcmp_fd("%x", format))
		ft_putnbrhexa_fd(fd, (unsigned int)va_arg(*args, int), 1, count);
	else if (!ft_strcmp_fd("%X", format))
		ft_putnbrhexa_fd(fd, (unsigned int)va_arg(*args, int), 0, count);
	else if (!ft_strcmp_fd("%%", format))
		ft_putstr_fd(fd, "%", count);
}

int	ft_printf_fd(const char *s, ...)
{
	va_list		args;
	size_t		i;
	const char	*format;
	int			count;

	if (!s)
		return (-1);
	va_start(args, s);
	count = 0;
	i = 0;
	while (s[i])
	{
		format = get_format(s + i);
		if (format)
		{
			i += ft_strlen_fd(format);
			handle_format(&args, 1, format, &count);
		}
		else
		{
			ft_putchar_fd(1, s[i], &count);
			i++;
		}
	}
	return (count);
}

int	ft_dprintf_fd(int fd, const char *s, ...)
{
	va_list		args;
	size_t		i;
	const char	*format;
	int			count;

	if (!s)
		return (-1);
	va_start(args, s);
	count = 0;
	i = 0;
	while (s[i])
	{
		format = get_format(s + i);
		if (format)
		{
			i += ft_strlen_fd(format);
			handle_format(&args, fd, format, &count);
		}
		else
		{
			ft_putchar_fd(fd, s[i], &count);
			i++;
		}
	}
	return (count);
}
