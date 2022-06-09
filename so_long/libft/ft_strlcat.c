/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldusty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 20:12:37 by ldusty            #+#    #+#             */
/*   Updated: 2021/11/10 20:12:39 by ldusty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dsize)
{
	char		*d;
	const char	*s;
	size_t		dlen;
	size_t		size;

	d = dst;
	s = src;
	size = dsize;
	while (size-- && *d)
		d++;
	dlen = d - dst;
	size = dsize - dlen;
	if (!size)
		return (dlen + ft_strlen(s));
	while (*s)
	{
		if (size != 1)
		{
			*d++ = *s;
			size--;
		}
		s++;
	}
	*d = '\0';
	return (dlen + (s - src));
}
