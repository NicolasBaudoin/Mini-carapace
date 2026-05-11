/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uuenkhba <uuenkhba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 12:25:48 by uuenkhba          #+#    #+#             */
/*   Updated: 2026/02/11 05:47:38 by uuenkhba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_fd.h"

static char	*extract_line(char **str)
{
	char	*endline;
	char	*line;
	char	*temp;

	endline = gnl_ft_strchr(*str, '\n');
	line = gnl_ft_strndup(*str, endline - *str + 1);
	if (!line)
		return (NULL);
	temp = *str;
	*str = gnl_ft_strndup(endline + 1, gnl_ft_strlen(endline));
	free(temp);
	if (!*str)
		return (NULL);
	return (line);
}

static int	read_fd(char **str, int fd)
{
	char		*buffer;
	int			code;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (-1);
	code = read(fd, buffer, BUFFER_SIZE);
	if (code > 0)
	{
		buffer[code] = '\0';
		*str = gnl_ft_strjoin(*str, buffer);
	}
	free(buffer);
	if (!*str)
		return (-1);
	return (code);
}

static void	free_str(char **str)
{
	free(*str);
	*str = NULL;
}

char	*get_next_line_fd(int fd)
{
	static char	*str[1024];
	char		*line;
	int			code;

	if (fd < 0 || fd >= 1024)
		return (NULL);
	while (!gnl_ft_strchr(str[fd], '\n'))
	{
		code = read_fd(&str[fd], fd);
		if (code <= 0)
		{
			line = NULL;
			if (str[fd] && gnl_ft_strlen(str[fd]) > 0 && code != -1)
				line = gnl_ft_strndup(str[fd], gnl_ft_strlen(str[fd]));
			if (str[fd])
				free_str(&str[fd]);
			return (line);
		}
	}
	line = extract_line(&str[fd]);
	if (!line || fd == 0)
		free_str(&str[fd]);
	return (line);
}
