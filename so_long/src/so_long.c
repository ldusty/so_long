/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldusty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:07:17 by ldusty            #+#    #+#             */
/*   Updated: 2022/02/13 06:46:54 by ldusty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int argc, char **argv)
{
	t_ctrl	ctrl;

	if (argc == 2)
	{
		init_var(&ctrl);
		open_map(argv[1], &ctrl);
		check_map(&ctrl);
		init_mlx(&ctrl);
		start_game(ctrl);
	}
	else
		ft_putstr_fd("Error\nInvalid arguments", 1);
	return (0);
}
