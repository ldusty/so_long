/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_game_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldusty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:05:16 by ldusty            #+#    #+#             */
/*   Updated: 2022/02/13 06:46:54 by ldusty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_exit(t_ctrl *ctrl, int extype)
{
	if (ctrl)
	{
		if (ctrl->map)
			remove_map(ctrl->map);
		if (ctrl->mlx)
		{
			free(ctrl->mlx);
		}
	}
	exit(extype);
}

void	remove_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	error_and_exit(char *str, t_ctrl *ctrl)
{
	ft_putstr_fd(str, 1);
	ft_exit(ctrl, 1);
}

int	exit_button(t_ctrl *ctrl)
{
	ft_exit(ctrl, 1);
	return (0);
}
