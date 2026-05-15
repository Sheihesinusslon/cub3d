/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_interact_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngusev <ngusev@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 00:00:00 by ngusev            #+#    #+#             */
/*   Updated: 2026/05/12 00:00:00 by ngusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*get_cell_ptr(t_map *map, int y, int x)
{
	int	len;

	if (y < 0 || y >= map->height || x < 0)
		return (NULL);
	len = ft_strlen(map->grid[y]);
	if (x >= len)
		return (NULL);
	return (&map->grid[y][x]);
}

static int	toggle_door_cell(char *cell)
{
	if (!cell)
		return (0);
	if (*cell == CHAR_DOOR)
	{
		*cell = CHAR_DOOR_OPEN;
		return (1);
	}
	if (*cell == CHAR_DOOR_OPEN)
	{
		*cell = CHAR_DOOR;
		return (1);
	}
	return (0);
}

int	toggle_door_bonus(t_game *game)
{
	double	dist;
	int		x;
	int		y;
	char	*cell;

	dist = 0.35;
	while (dist <= game->bonus.door_reach)
	{
		x = (int)(game->player.pos_x + game->player.dir_x * dist);
		y = (int)(game->player.pos_y + game->player.dir_y * dist);
		cell = get_cell_ptr(&game->map, y, x);
		if (toggle_door_cell(cell))
			return (game->needs_redraw = true, 1);
		dist += 0.1;
	}
	return (0);
}
