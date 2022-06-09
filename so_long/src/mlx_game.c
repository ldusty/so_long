/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_game.                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldusty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:04:15 by ldusty            #+#    #+#             */
/*   Updated: 2022/02/13 07:41:57 by ldusty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	move(char next_pos, int keypress, t_ctrl *ctrl)
{
	if (keypress == 13)
		ctrl->player_y = ctrl->player_y - 1;
	else if (keypress == 0)
		ctrl->player_x = ctrl->player_x - 1;
	else if (keypress == 1)
		ctrl->player_y = ctrl->player_y + 1;
	else if (keypress == 2)
		ctrl->player_x = ctrl->player_x + 1;
	is_collected(next_pos, ctrl);
}

int	put_image(size_t x, size_t y, t_ctrl *ctrl)
{
	char	symb;
	void	*mlx;
	void	*win;

	symb = ctrl->map[y][x];
	mlx = ctrl->mlx;
	win = ctrl->win;
	if (symb == '0')
		mlx_put_image_to_window(mlx, win, ctrl->pic_back, x * 60, y * 60);
	if (symb == '1')
		mlx_put_image_to_window(mlx, win, ctrl->pic_wall, x * 60, y * 60);
	if (symb == 'E')
		mlx_put_image_to_window(mlx, win, ctrl->pic_exit, x * 60, y * 60);
	if (symb == 'C')
		mlx_put_image_to_window(mlx, win, ctrl->pic_coll, x * 60, y * 60);
	if (symb == 'P')
		mlx_put_image_to_window(mlx, win, ctrl->pic_player, x * 60, y * 60);
	return (0);
}

int	pic_to_window(t_ctrl *ctrl)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < ctrl->map_h)
	{
		x = 0;
		while (x < ctrl->map_w)
		{
			put_image(x, y, ctrl);
			x++;
		}
		y++;
	}
	return (0);
}

int	key_event(int keypress, t_ctrl *ctrl)
{
	char	next_pos;

	if ((keypress == 53) || (keypress == 0) || (keypress == 2)
		|| (keypress == 1) || (keypress == 13))
	{
		next_pos = set_next_pos(keypress, ctrl);
		if (next_pos != '1')
		{
			if (next_pos != 'E')
				count_of_moves();
			else if (ctrl->nb_c == 0)
				count_of_moves();
			if (!is_exit(next_pos, ctrl))
			{
				ctrl->map[ctrl->player_y][ctrl->player_x] = '0';
				move(next_pos, keypress, ctrl);
				ctrl->map[ctrl->player_y][ctrl->player_x] = 'P';
			}
		}
	}
	return (0);
}

void	start_game(t_ctrl ctrl)
{
	mlx_loop_hook(ctrl.mlx, &pic_to_window, &ctrl);
	mlx_key_hook(ctrl.win, &key_event, &ctrl);
	mlx_hook(ctrl.win, 17, 0, &exit_button, &ctrl);
	mlx_loop(ctrl.mlx);
}
