/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shwatana <shwatana@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 10:36:52 by shwatana          #+#    #+#             */
/*   Updated: 2022/04/24 03:15:59 by shwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_buf(char *str, int fd);
static char	*format_line(char *strage);
static char	*ft_strage(char *strage);

char	*get_next_line(int fd)
{
	char		*line;
	static char	*strage[256];

	if (fd < 0 || 256 < fd || BUFFER_SIZE <= 0)
		return (NULL);
	strage[fd] = read_buf(strage[fd], fd);
	if (strage[fd] == NULL)
		return (NULL);
	line = format_line(strage[fd]);
	strage[fd] = ft_strage(strage[fd]);
	return (line);
}

static char	*format_line(char *strage)
{
	size_t	i;
	char	*line;

	i = 0;
	if (strage[i] == '\0')
		return (NULL);
	while (strage[i] != '\n' && strage[i] != '\0')
		i++;
	line = malloc(sizeof(char) * (i + 1 + (strage[i] == '\n')));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (strage[i] != '\n' && strage[i] != '\0')
	{
		line[i] = strage[i];
		i++;
	}
	if (strage[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_strage(char *strage)
{
	size_t	size;
	size_t	i;
	char	*new_strage;

	size = 0;
	while (strage[size] != '\0' && strage[size] != '\n')
		size++;
	if (strage[size] == '\0')
	{
		free(strage);
		return (NULL);
	}
	new_strage = (char *)malloc(sizeof(char) * (ft_strlen(strage) - size + 1));
	if (new_strage == NULL)
		return (NULL);
	size++;
	i = 0;
	while (strage[size] != '\0')
		new_strage[i++] = strage[size++];
	new_strage[i] = '\0';
	free(strage);
	return (new_strage);
}

static char	*read_buf(char *strage, int fd)
{
	char	*buf;
	ssize_t	read_size;

	buf = (char *)malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	while (ft_strchr(strage, '\n') == NULL)
	{
		read_size = read(fd, buf, (size_t)BUFFER_SIZE);
		if (read_size <= 0)
		{
			free(buf);
			if (read_size == 0)
				return (strage);
			return (NULL);
		}
		buf[read_size] = '\0';
		strage = ft_strjoin(strage, buf);
		if (strage == NULL)
			return (NULL);
	}
	free(buf);
	return (strage);
}
