/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shwatana <shwatana@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 10:36:52 by shwatana          #+#    #+#             */
/*   Updated: 2022/03/27 15:00:13 by shwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list	new_str_list(int fd);
static t_list	find_list_by_fd(int fd, t_list *str_list);
static t_list	read_buf(int fd);

char	*get_next_line(int fd)
{
	int		n;
	char	*buf;
	char	*line;
	char	*target;
	t_list	*str_list;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (str_list == NULL)
	{
		str_list = new_str_list(fd);
		if (str_list == NULL)
			return (NULL);
	}
	target = find_list_by_fd(fd, str_list);
	// buf = (char *)malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
	// n = read(fd, buf, sizeof buf);
	// if (n < 0)
	// 	return (NULL);
	// if (n == 0)
	// 	return (NULL);
	return (line);
}

static t_list	*find_list_by_fd(int fd, t_list *str_list)
{
	t_list	*new_list;

	while (str_list == NULL)
	{
		if (str_list->fd == fd)
			return (str_list);
		str_list = str_list->prev;
	}
	new_list = new_str_list(fd);
	if (new_list == NULL)
		return (NULL);
	return (new_list);
}

static t_list	new_str_list(int fd)
{
	t_list	*new_list;

	new_list = (t_list *)malloc(sizeof(t_list));
	if (new_list == NULL)
		return (NULL);
	new_list->fd = fd;
	new_list->text = NULL;
	new_list->prev = NULL;
	new_list->next = NULL;
	return (new_list);
}

static bool	read_buf(t_list *str_list)
{
	char	*buf;
	int		read_size;

	if (str_list == NULL)
		return (NULL);
	while (true)
	{
		buf = (char *)malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
		if (buf == NULL)
			return (NULL);
		read_size = read(str_list->fd, buf, BUFFER_SIZE);
		if (read_size <= 0)
		{
			free(buf);
			if (read_size == 0)
				return (true);
			return (false);
		}
		buf[read_size] = '\0';
		// node->storage = ft_strjoin_with_free(node->storage, buf);
		free(buf);
		if (str_list->text == NULL)
			return (false);
	}
}
