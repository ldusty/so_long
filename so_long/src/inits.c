/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldusty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:04:14 by ldusty            #+#    #+#             */
/*   Updated: 2022/02/19 09:44:44 by ldusty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	pic_to_image(t_ctrl *ctrl)
{
	int	*w;
	int	*h;

	w = &ctrl->pic_w;
	h = &ctrl->pic_h;
	ctrl->pic_back = mlx_xpm_file_to_image(ctrl->mlx, "img/floor.xpm", w, h);
	if (!ctrl->pic_back)
		error_and_exit("Error\nMLX xpm file to img failed", ctrl);
	ctrl->pic_wall = mlx_xpm_file_to_image(ctrl->mlx, "img/wall.xpm", w, h);
	if (!ctrl->pic_wall)
		error_and_exit("Error\nMLX xpm file to img failed", ctrl);
	ctrl->pic_exit = mlx_xpm_file_to_image(ctrl->mlx, "img/exit.xpm", w, h);
	if (!ctrl->pic_exit)
		error_and_exit("Error\nMLX xpm file to img failed", ctrl);
	ctrl->pic_coll = mlx_xpm_file_to_image(ctrl->mlx, "img/item.xpm", w, h);
	if (!ctrl->pic_coll)
		error_and_exit("Error\nMLX xpm file to img failed", ctrl);
	ctrl->pic_player = mlx_xpm_file_to_image(ctrl->mlx, "img/player.xpm", w, h);
	if (!ctrl->pic_player)
		error_and_exit("Error\nMLX xpm file to img failed", ctrl);
}

void	init_var(t_ctrl *ctrl)
{
	ctrl->nb_c = 0;
	ctrl->nb_p = 0;
	ctrl->nb_e = 0;
	ctrl->mlx = NULL;
	ctrl->win = NULL;
	ctrl->map = NULL;
	ctrl->map_w = 0;
	ctrl->map_h = 0;
	ctrl->player_x = 0;
	ctrl->player_y = 0;
	ctrl->pic_back = NULL;
	ctrl->pic_wall = NULL;
	ctrl->pic_exit = NULL;
	ctrl->pic_coll = NULL;
	ctrl->pic_player = NULL;
	ctrl->pic_w = 0;
	ctrl->pic_h = 0;
}

void	init_mlx(t_ctrl *ctrl)
{
	size_t	w;
	size_t	h;

	w = ctrl->map_w;
	h = ctrl->map_h;
	ctrl->pic_w = 60;
	ctrl->pic_h = 60;
	ctrl->mlx = mlx_init();
	if (!ctrl->mlx)
		error_and_exit("Error\nMLX init failed", ctrl);
	ctrl->win = mlx_new_window(ctrl->mlx, w * 60, h * 60, "so_long");
	if (!ctrl->win)
		error_and_exit("Error\nMLX new window failed", ctrl);
	pic_to_image(ctrl);
}
