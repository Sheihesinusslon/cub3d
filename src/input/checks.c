/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngusev <ngusev@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 16:24:03 by ngusev            #+#    #+#             */
/*   Updated: 2026/05/05 16:24:06 by ngusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	check_color(int *color)
{
	if (color[0] < 0 || color[0] > 255)
		return (-1);
	if (color[1] < 0 || color[1] > 255)
		return (-1);
	if (color[2] < 0 || color[2] > 255)
		return (-1);
	return (0);
}

static int check_texture_path(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (-1);
	close(fd);
	return (0);
}

int	check_textures(t_map *map)
{
	if (!map->no_tex || !map->so_tex || !map->we_tex || !map->ea_tex)
		return (printf(ERR_TEXTURE), -1);
	if (check_texture_path(map->no_tex) || check_texture_path(map->so_tex) 
		|| check_texture_path(map->we_tex) || check_texture_path(map->ea_tex))
		return (printf(ERR_TEXTURE_PATH), -1);
	return (0);
}
