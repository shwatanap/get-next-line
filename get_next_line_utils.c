/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shwatana <shwatana@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 18:13:17 by shwatana          #+#    #+#             */
/*   Updated: 2022/04/20 18:11:56 by shwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_utils.h"

static void		*ft_calloc(size_t count, size_t size);
char			*ft_strdup(const char *str);
size_t			ft_strlen(const char *s);
void			*ft_memmove(void *dst, const void *src, size_t size);

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
	new_str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (new_str == NULL)
		return (NULL);
	ft_memmove(new_str, s1, s1_len + 1);
	ft_memmove(new_str + s1_len, s2, s2_len + 1);
	return (new_str);
}

char	*ft_strdup(const char *str)
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

void	*ft_memmove(void *dst, const void *src, size_t size)
{
	unsigned char	*dst_p;
	unsigned char	*src_p;

	if (size == 0)
		return (dst);
	if (dst == NULL && src == NULL)
		return (NULL);
	dst_p = (unsigned char *)dst;
	src_p = (unsigned char *)src;
	if (dst_p < src_p)
		while (size--)
			*dst_p++ = *src_p++;
	else
		while (size--)
			dst_p[size] = src_p[size];
	return (dst_p);
}

static void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	char	*str;
	size_t	m_size;
	size_t	i;

	if (size != 0 && SIZE_MAX / size < count)
		return (NULL);
	m_size = count * size;
	if (m_size == 0)
		m_size = 1;
	p = malloc(m_size);
	if (p == NULL)
		return (NULL);
	str = (char *)p;
	i = 0;
	while (i < size * count)
	{
		str[i] = '\0';
		i++;
	}
	return (p);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
