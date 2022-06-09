/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldusty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 18:01:11 by ldusty            #+#    #+#             */
/*   Updated: 2022/03/22 15:41:17 by ldusty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <mlx.h>
# include "../libft/libft.h"

typedef struct s_ctrl
{
	void	*mlx;
	void	*win;
	char	**map;
	size_t	map_w;
	size_t	map_h;
	int		player_x;
	int		player_y;
	int		nb_c;
	int		nb_e;
	int		nb_p;
	void	*pic_back;
	void	*pic_wall;
	void	*pic_exit;
	void	*pic_coll;
	void	*pic_player;
	int		pic_w;
	int		pic_h;
}	t_ctrl;

void	init_var(t_ctrl *ctrl);
void	init_mlx(t_ctrl *ctrl);
void	open_map(char *path, t_ctrl *ctrl);
void	check_map(t_ctrl *ctrl);

void	start_game(t_ctrl ctrl);
char	set_next_pos(int keypress, t_ctrl *ctrl);
int		is_exit(char next_pos, t_ctrl *ctrl);
void	is_collected(char next_pos, t_ctrl *ctrl);
int		ft_exit(t_ctrl *ctrl, int extype);
int		exit_button(t_ctrl *ctrl);
void	count_of_moves(void);
void	error_and_exit(char *str, t_ctrl *ctrl);
void	remove_map(char **map);

#endif
