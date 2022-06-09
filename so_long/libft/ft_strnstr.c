/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldusty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 16:19:13 by ldusty            #+#    #+#             */
/*   Updated: 2021/11/10 16:19:15 by ldusty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	h;
	size_t	n;

	h = 0;
	n = 0;
	if (!*needle)
		return ((char *) haystack);
	while (haystack[h] && h < len)
	{
		if (haystack[h] == needle[0])
		{
			while (needle[n] && haystack[h + n] == needle[n] && h + n < len)
			{
				if (!needle[n + 1])
					return ((char *) &haystack[h]);
				n++;
			}
		}
		h++;
	}
	return (NULL);
}
