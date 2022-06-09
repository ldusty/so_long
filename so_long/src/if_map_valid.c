/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_map_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldusty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 13:03:33 by ldusty            #+#    #+#             */
/*   Updated: 2022/03/19 11:11:11 by ldusty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_wall(char c, int index, int size, t_ctrl *ctrl)
{
	if ((index == 0) || (index == size - 1))
	{
		if (c != '1')
			error_and_exit("Error\n Wrong walls on map\n", ctrl);
	}
}

void	check_smb_on_map(t_ctrl *ctrl, int i, int j)
{
	char	smb;

	smb = ctrl->map[i][j];
	if ((smb != '1') && (smb != '0') && (smb != 'C') && (smb != 'E') && \
		(smb != 'P'))
		error_and_exit("Error\n Wrong symbols on map\n", ctrl);
	if (smb == 'C')
		ctrl->nb_c = ctrl->nb_c + 1;
	else if (smb == 'E')
		ctrl->nb_e = ctrl->nb_e + 1;
	else if (smb == 'P')
		ctrl->nb_p = ctrl->nb_p + 1;
}

void	check_map(t_ctrl *ctrl)
{
	size_t	i;
	int		j;

	i = -1;
	while (++i < ctrl->map_h)
	{
		if (ft_strlen(ctrl->map[i]) != ctrl->map_w)
			error_and_exit("Error\nMap is not rectangular", NULL);
		j = -1;
		while (ctrl->map[i][++j])
		{
			if (ctrl->map[i][j] == 'P')
			{
				ctrl->player_x = j;
				ctrl->player_y = i;
			}
			check_smb_on_map(ctrl, i, j);
			check_wall(ctrl->map[i][j], i, ctrl->map_h, ctrl);
			check_wall(ctrl->map[i][j], j, ctrl->map_w, ctrl);
		}
	}
	if ((ctrl->nb_c < 1) || (ctrl->nb_e < 1) || (ctrl->nb_p != 1))
		error_and_exit("Error\nWrong numbers of C, E, or P\n", ctrl);
}
