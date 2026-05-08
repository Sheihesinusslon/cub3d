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

static int	check_xpm_extension(char *path)
{
	int	len;

	len = ft_strlen(path);
	if (len < 4)
		return (-1);
	if (ft_strncmp(path + len - 4, ".xpm", 4) != 0)
		return (-1);
	return (0);
}

static int	check_texture_path(char *path)
{
	int	fd;

	if (!path)
		return (-1);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (-1);
	close(fd);
	return (0);
}

int	check_textures(t_map *map)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!map->textures[i].path)
			return (printf(ERR_TEXTURE), -1);
		if (check_xpm_extension(map->textures[i].path))
			return (printf(ERR_TEXTURE_XPM), -1);
		if (check_texture_path(map->textures[i].path))
			return (printf(ERR_TEXTURE_PATH), -1);
		i++;
	}
	return (0);
}
