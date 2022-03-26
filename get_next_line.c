/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shwatana <shwatana@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 10:36:52 by shwatana          #+#    #+#             */
/*   Updated: 2022/03/26 12:18:07 by shwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int		n;
	char	*buf;

	if (fd < 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
	n = read(fd, buf, sizeof buf);
	if (n < 0)
		return (NULL);
	if (n == 0)
		return (NULL);
	return (buf);
}
