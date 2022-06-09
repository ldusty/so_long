/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldusty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:44:50 by ldusty            #+#    #+#             */
/*   Updated: 2021/11/10 17:44:53 by ldusty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dst1;
	unsigned const char	*src1;

	dst1 = dst;
	src1 = src;
	if (dst == src)
		return (dst);
	while (n--)
		*dst1++ = *src1++;
	return (dst);
}
