/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shwatana <shwatana@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 18:13:17 by shwatana          #+#    #+#             */
/*   Updated: 2022/04/02 01:07:42 by shwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_utils.h"

static void		*ft_calloc(size_t num, size_t size);
static char		*ft_strdup(const char *str);
static size_t	ft_strlcat(char *dst, const char *src, size_t size);
static size_t	ft_strlcpy(char *dest, const char *src, size_t size);
static size_t	ft_strlen(const char *s);

char	*ft_strjoin(const char *s1, const char *s2)
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
	new_str = (char *)ft_calloc(s1_len + s2_len + 1, sizeof(char));
	if (new_str == NULL)
		return (NULL);
	ft_strlcpy(new_str, s1, s1_len + 1);
	ft_strlcat(new_str, s2, s1_len + s2_len + 1);
	return (new_str);
}

static char	*ft_strdup(const char *str)
{
	int		i;
	int		len;
	char	*new_char;

	len = ft_strlen(str);
	new_char = (char *)ft_calloc(len + 1, sizeof(char));
	if (new_char == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		new_char[i] = str[i];
		i++;
	}
	return (new_char);
}

static void	*ft_calloc(size_t num, size_t size)
{
	void	*buf;
	size_t	i;
	char	*str;

	buf = (void *)malloc(size * num);
	if (buf != NULL)
	{
		str = (char *)buf;
		i = 0;
		while (i < size * num)
		{
			str[i] = '\0';
			i++;
		}
	}
	return (buf);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	cnt;

	if (size == 0 || ft_strlen(dst) >= size)
		return (size + ft_strlen(src));
	cnt = 0;
	while (*dst && (cnt < size - 1))
	{
		dst++;
		cnt++;
	}
	while (*src && (cnt < size - 1))
	{
		*dst++ = *src++;
		cnt++;
	}
	*dst = '\0';
	while (*src++)
		cnt++;
	return (cnt);
}

static size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	srclen;

	i = 0;
	srclen = ft_strlen(src);
	if (size == 0)
		return (srclen);
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (srclen);
}

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
