/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_game_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldusty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:02:12 by ldusty            #+#    #+#             */
/*   Updated: 2022/02/13 09:43:53 by ldusty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	count_of_moves(void)
{
	static int	i;

	ft_putstr_fd("Number of moves: ", 1);
	ft_putnbr_fd(++i, 1);
	ft_putstr_fd("\n", 1);
}

void	is_collected(char next_pos, t_ctrl *ctrl)
{
	if (next_pos == 'C')
		ctrl->nb_c = ctrl->nb_c - 1;
}

int	is_exit(char next_pos, t_ctrl *ctrl)
{
	if (next_pos == 'E')
	{
		if (ctrl->nb_c == 0)
			ft_exit(ctrl, 1);
		else
			return (1);
	}
	return (0);
}

char	set_next_pos(int keypress, t_ctrl *ctrl)
{
	int		x;
	int		y;
	char	**map;
	char	next_pos;

	x = ctrl->player_x;
	y = ctrl->player_y;
	map = ctrl->map;
	next_pos = '\0';
	if (keypress == 53)
		ft_exit(ctrl, 1);
	else if (keypress == 13)
		next_pos = map[y - 1][x];
	else if (keypress == 0)
		next_pos = map[y][x - 1];
	else if (keypress == 1)
		next_pos = map[y + 1][x];
	else if (keypress == 2)
		next_pos = map[y][x + 1];
	return (next_pos);
}
