/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imac <imac@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 23:06:51 by whitepunk         #+#    #+#             */
/*   Updated: 2021/02/22 22:31:51 by imac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char			*ft_strdup(const char *s1)
{
	char *s1_cpy;

	s1_cpy = (char *)malloc(ft_strlen(s1) * sizeof(char) + 1);
	if (s1_cpy == NULL)
		return (NULL);
	ft_strlcpy(s1_cpy, s1, ft_strlen(s1) * sizeof(char) + 1);
	return (s1_cpy);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*summ;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	summ = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (summ == NULL)
		return (NULL);
	ft_strlcpy(summ, s1, ft_strlen(s1) + 1);
	ft_strlcpy(summ + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	return (summ);
}

char			*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == s[i])
		return ((char *)&s[i]);
	return (NULL);
}

size_t			ft_strlen(const char *s)
{
	size_t		i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char		*src_cpy;

	if (dst == NULL || src == NULL)
		return (0);
	if (dstsize == 0)
		return (ft_strlen(src));
	src_cpy = (char *)src;
	if (ft_strlen(src) + 1 <= dstsize)
	{
		while (*src_cpy != '\0')
			*dst++ = *src_cpy++;
		*dst = '\0';
	}
	else
	{
		while (--dstsize > 0)
			*dst++ = *src_cpy++;
		*dst = '\0';
	}
	return (ft_strlen(src));
}
