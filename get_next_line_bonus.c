/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shwatana <shwatana@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 10:36:52 by shwatana          #+#    #+#             */
/*   Updated: 2022/06/13 12:55:18 by shwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*read_buf(char *str, int fd);
static char	*format_line(char *storage);
static char	*ft_storage(char *storage);

char	*get_next_line(int fd)
{
	char		*line;
	static char	*storage[256];

	if (fd < 0 || 256 <= fd || read(fd, NULL, 0) < 0
		|| (size_t)BUFFER_SIZE <= 0)
		return (NULL);
	storage[fd] = read_buf(storage[fd], fd);
	if (storage[fd] == NULL)
		return (NULL);
	line = format_line(storage[fd]);
	storage[fd] = ft_storage(storage[fd]);
	return (line);
}

static char	*read_buf(char *storage, int fd)
{
	char	*buf;
	ssize_t	read_size;

	buf = (char *)malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	while (ft_strchr(storage, '\n') == NULL)
	{
		read_size = read(fd, buf, (size_t)BUFFER_SIZE);
		if (read_size <= 0)
		{
			free(buf);
			if (read_size == 0)
				return (storage);
			return (NULL);
		}
		buf[read_size] = '\0';
		storage = ft_strjoin(storage, buf);
		if (storage == NULL)
			return (NULL);
	}
	free(buf);
	return (storage);
}

static char	*format_line(char *storage)
{
	size_t	i;
	char	*line;

	i = 0;
	if (storage[i] == '\0')
		return (NULL);
	while (storage[i] != '\n' && storage[i] != '\0')
		i++;
	line = malloc(sizeof(char) * (i + 1 + (storage[i] == '\n')));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (storage[i] != '\n' && storage[i] != '\0')
	{
		line[i] = storage[i];
		i++;
	}
	if (storage[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*ft_storage(char *storage)
{
	size_t	size;
	size_t	i;
	char	*new_storage;

	size = 0;
	while (storage[size] != '\0' && storage[size] != '\n')
		size++;
	if (storage[size] == '\0')
	{
		free(storage);
		return (NULL);
	}
	new_storage = malloc(sizeof(char) * (ft_strlen(storage) - size + 1));
	if (new_storage == NULL)
		return (NULL);
	size++;
	i = 0;
	while (storage[size] != '\0')
		new_storage[i++] = storage[size++];
	new_storage[i] = '\0';
	free(storage);
	return (new_storage);
}
