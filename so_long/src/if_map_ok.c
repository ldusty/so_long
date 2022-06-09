/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_map_ok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldusty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:02:31 by ldusty            #+#    #+#             */
/*   Updated: 2022/03/20 12:10:01 by ldusty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	sizeof_map(char *path, t_ctrl *ctrl)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd == 0)
		error_and_exit("Error\nFailed to open map", ctrl);
	line = get_next_line(fd);
	if (line == 0)
		error_and_exit("Error\nMalloc failed or wrong name of map", ctrl);
	ctrl->map_w = ft_strlen(line) - 1;
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	ctrl->map_h = i;
}

char	**make_map(int fd, size_t len)
{
	char	**map;
	size_t	i;

	i = 0;
	map = malloc(sizeof (char *) * (len + 1));
	if (map == NULL)
		error_and_exit("Error\nMalloc failed", NULL);
	while (i < len)
	{
		map[i] = get_next_line(fd);
		if (map[i] == NULL)
			error_and_exit("Error\nMalloc failed", NULL);
		if (ft_strchr(map[i], '\n'))
			*(ft_strchr(map[i], '\n')) = '\0';
		i++;
	}
	map[i] = NULL;
	return (map);
}

void	open_map(char *path, t_ctrl *ctrl)
{
	int		fd;
	int		dot_pos;
	char	*str;

	dot_pos = ft_strrchr(path, '.') - path;
	str = ft_substr(path, dot_pos, 5);
	if (!str)
		error_and_exit("Error\nMalloc failed", ctrl);
	if (ft_strncmp(".ber", str, 5))
	{
		free(str);
		error_and_exit("Error\nWrong extension of the map -> need .ber", ctrl);
	}
	free(str);
	sizeof_map(path, ctrl);
	fd = open(path, O_RDONLY);
	if (fd == 0)
		error_and_exit("Error\nFailed to open map", NULL);
	ctrl->map = make_map(fd, ctrl->map_h);
}
