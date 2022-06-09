/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldusty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 13:33:38 by ldusty            #+#    #+#             */
/*   Updated: 2021/11/12 13:33:40 by ldusty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	num;

	if (n < 0)
	{
		ft_putchar_fd(45, fd);
		num = (unsigned int)(-n);
	}
	else
		num = (unsigned int)(n);
	if (num >= 10)
		ft_putnbr_fd((int)(num / 10), fd);
	ft_putchar_fd((char)(num % 10 + 48), fd);
}
