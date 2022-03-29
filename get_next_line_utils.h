/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shwatana <shwatana@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 10:32:35 by shwatana          #+#    #+#             */
/*   Updated: 2022/03/29 10:09:29 by shwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_UTILS_H
# define GET_NEXT_LINE_UTILS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdint.h>
# include <errno.h>

# define BUFFER_SIZE 32

typedef struct s_list
{
	int				fd;
	char			*text;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

char	*ft_strjoin(const char *s1, const char *s2);

#endif
