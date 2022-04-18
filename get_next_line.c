/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shwatana <shwatana@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 10:36:52 by shwatana          #+#    #+#             */
/*   Updated: 2022/04/18 18:22:29 by shwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_buf(char *str, int fd);
static char	*format_line(char *strage);
static char	*ft_strage(char *strage);

char	*get_next_line(int fd)
{
	char		*line;
	static char	*strage;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	strage = read_buf(strage, fd);
	if (strage == NULL)
		return (NULL);
	// line = format_line(line, strage);
	// printf("======\n");
	// printf("%s\n", format_line(line, strage));
	// printf("======\n");
	line = format_line(strage);
	strage = ft_strage(strage);
	return (line);
}

static char	*format_line(char *strage)
{
	size_t	i;
	char	*line;

	i = 0;
	if (strage == NULL)
		return (NULL);
	while (strage[i] == '\n' || strage[i] == '\0')
		i++;
	line = malloc(sizeof(char) * (i + 1 + (strage[i] == '\n')));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (strage[i] && strage[i] != '\n')
	{
		line[i] = strage[i];
		i++;
	}
	if (strage[i] == '\n')
	{
		line[i] = strage[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_strage(char *strage)
{
	size_t	size;
	int		c;
	char	*new_strage;

	size = 0;
	while (strage[size] && strage[size] != '\n')
		size++;
	if (strage[size] == '\0')
	{
		free(strage);
		return (NULL);
	}
	new_strage = (char *)malloc(sizeof(char) * (ft_strlen(strage) - size + 1));
	if (!new_strage)
		return (NULL);
	size++;
	c = 0;
	while (strage[size])
		new_strage[c++] = strage[size++];
	new_strage[c] = '\0';
	free(strage);
	return (new_strage);
}

static char	*read_buf(char *strage, int fd)
{
	char	*buf;
	size_t	read_size;

	while (true)
	{
		buf = (char *)malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
		if (buf == NULL)
			return (NULL);
		read_size = read(fd, buf, BUFFER_SIZE);
		// printf("read_size: %d\n", read_size);
		if (read_size <= 0)
		{
			free(buf);
			if (read_size == 0)
				return (strage);
			return (NULL);
		}
		buf[read_size] = '\0';
		strage = ft_strjoin(strage, buf);
		free(buf);
		if (strage == NULL)
			return (NULL);
	}
}
