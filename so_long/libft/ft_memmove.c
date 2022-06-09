/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldusty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 18:56:50 by ldusty            #+#    #+#             */
/*   Updated: 2021/11/10 18:56:52 by ldusty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dst1;
	unsigned const char	*src1;

	dst1 = dst;
	src1 = src;
	if (!dst && !src)
		return (dst);
	if (dst < src)
		ft_memcpy(dst, src, len);
	else
		while (len--)
			*(dst1 + len) = *(src1 + len);
	return (dst);
}
