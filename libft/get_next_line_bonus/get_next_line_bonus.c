/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uuenkhba <uuenkhba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 23:01:03 by uuenkhba          #+#    #+#             */
/*   Updated: 2026/02/11 05:40:40 by uuenkhba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_free_s(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*clean_storage(char *storage)
{
	char	*new_storage;
	char	*ptr;
	int		len;

	ptr = ft_strchr_gb(storage, '\n');
	if (!ptr)
	{
		new_storage = NULL;
		return (ft_free_s(&storage));
	}
	else
		len = (ptr - storage) + 1;
	if (!storage[len])
		return (ft_free_s(&storage));
	new_storage = ft_substr_gb(storage, len, ft_strlen_gb(storage) - len);
	ft_free_s(&storage);
	if (!new_storage)
		return (NULL);
	return (new_storage);
}

char	*new_line(char *storage)
{
	char	*line;
	char	*ptr;
	int		len;

	ptr = ft_strchr_gb(storage, '\n');
	len = (ptr - storage) + 1;
	line = ft_substr_gb(storage, 0, len);
	if (!line)
		return (NULL);
	return (line);
}

char	*readbuf(int fd, char *storage)
{
	int		rid;
	char	*buffer;

	rid = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (ft_free_s(&storage));
	buffer[0] = '\0';
	while (rid > 0 && !ft_strchr_gb(buffer, '\n'))
	{
		rid = read (fd, buffer, BUFFER_SIZE);
		if (rid > 0)
		{
			buffer[rid] = '\0';
			storage = ft_strjoin_gb(storage, buffer);
		}
	}
	free(buffer);
	if (rid == -1)
		return (ft_free_s(&storage));
	return (storage);
}

char	*get_next_line_b(int fd)
{
	static char	*storage[OPEN_MAX];
	char		*line;

	if (fd < 0)
		return (NULL);
	if ((storage[fd] && !ft_strchr_gb(storage[fd], '\n')) || !storage[fd])
		storage[fd] = readbuf (fd, storage[fd]);
	if (!storage[fd])
		return (NULL);
	line = new_line(storage[fd]);
	if (!line)
		return (ft_free_s(&storage[fd]));
	storage[fd] = clean_storage(storage[fd]);
	return (line);
}
