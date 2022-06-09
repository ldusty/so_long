/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldusty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 13:48:31 by ldusty            #+#    #+#             */
/*   Updated: 2021/11/12 13:48:35 by ldusty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next_element;

	if ((!lst) || (!(*lst)) || (!del))
		return ;
	while (*lst)
	{
		next_element = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = next_element;
	}
}
