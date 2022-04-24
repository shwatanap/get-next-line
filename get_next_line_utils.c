/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shwatana <shwatana@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 21:32:44 by shwatana          #+#    #+#             */
/*   Updated: 2022/04/24 22:01:13 by shwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	char	chrc;
	size_t	i;
	size_t	len;

	if (str == NULL)
		return (NULL);
	len = ft_strlen(str) + 1;
	chrc = (char)c;
	i = 0;
	while (i < len)
	{
		if (str[i] == chrc)
			return ((char *)(str + i));
		i++;
	}
	return (NULL);
}

static void	*ft_memmove(void *dst, void *src, size_t size)
{
	unsigned char	*dst_p;
	unsigned char	*src_p;
	size_t			i;

	if (size == 0)
		return (dst);
	if (dst == NULL || src == NULL)
		return (NULL);
	dst_p = (unsigned char *)dst;
	src_p = (unsigned char *)src;
	i = 0;
	if (dst_p < src_p)
	{
		while (i < size)
		{
			dst_p[i] = src_p[i];
			i++;
		}
	}
	else
		while (size--)
			dst_p[size] = src_p[size];
	return (dst_p);
}

static char	*ft_strdup(char *str)
{
	size_t	len;
	char	*new_char;

	if (str == NULL)
		return (NULL);
	len = ft_strlen(str);
	new_char = (char *)malloc(sizeof(char) * (len + 1));
	if (new_char == NULL)
		return (NULL);
	ft_memmove(new_char, str, len + 1);
	return (new_char);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*new_str;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (s1 == NULL)
		return (ft_strdup(s2));
	else if (s2 == NULL)
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (new_str == NULL)
		return (NULL);
	ft_memmove(new_str, s1, s1_len + 1);
	ft_memmove(new_str + s1_len, s2, s2_len + 1);
	free(s1);
	return (new_str);
}
