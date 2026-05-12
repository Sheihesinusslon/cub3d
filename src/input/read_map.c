/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngusev <ngusev@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 16:25:23 by ngusev            #+#    #+#             */
/*   Updated: 2026/05/05 16:25:26 by ngusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_map(t_map *map)
{
	map->grid = NULL;
	map->width = 0;
	map->height = 0;
	map->floor_color = -1;
	map->ceil_color = -1;
}

static bool	has_cub_extension(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 5)
		return (false);
	if (ft_strncmp(filename + len - 4, ".cub", 5) != 0)
		return (false);
	return (true);
}

int	read_map(t_game *game, char *filename)
{
	int	fd;

	init_map(&game->map);
	if (!has_cub_extension(filename))
		return (printf(ERR_EXTENSION), -1);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (printf(ERR_FILE), -1);
	if (!parse_cub_file(fd, &game->map))
		return (free_map(game), close(fd), -1);
	close(fd);
	return (0);
}
