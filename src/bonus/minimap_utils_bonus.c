/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngusev <ngusev@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 00:00:00 by ngusev            #+#    #+#             */
/*   Updated: 2026/05/18 00:00:00 by ngusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	map_tile_color(char tile)
{
	if (tile == '1')
		return (MINIMAP_WALL_COLOR);
	if (tile == CHAR_DOOR || tile == CHAR_DOOR_OPEN)
		return (MINIMAP_DOOR_COLOR);
	if (tile == '0')
		return (MINIMAP_FLOOR_COLOR);
	return (MINIMAP_GRID_COLOR);
}

static char	read_tile(t_map *map, int x, int y)
{
	int	len;

	if (y < 0 || y >= map->height || x < 0)
		return (' ');
	len = ft_strlen(map->grid[y]);
	if (x >= len)
		return (' ');
	return (map->grid[y][x]);
}

static void	draw_cell(t_game *game, int px, int py, char tile)
{
	int	x;
	int	y;
	int	size;
	int	color;

	size = game->bonus.minimap_tile;
	color = map_tile_color(tile);
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			put_pixel(&game->screen, px + x, py + y, color);
			x++;
		}
		y++;
	}
}

void	draw_minimap_background_bonus(t_game *game, int origin_x, int origin_y)
{
	int	x;
	int	y;
	int	size;

	size = game->bonus.minimap_tile * game->bonus.minimap_radius * 2;
	y = -1;
	while (y <= size)
	{
		x = -1;
		while (x <= size)
		{
			put_pixel(&game->screen,
				origin_x + x,
				origin_y + y,
				MINIMAP_BG_COLOR);
			x++;
		}
		y++;
	}
}

void	draw_minimap_rows_bonus(t_game *game, double base_x, double base_y)
{
	int	x;
	int	y;
	int	gx;
	int	gy;

	y = 0;
	while (y < game->bonus.minimap_radius * 2)
	{
		x = 0;
		while (x < game->bonus.minimap_radius * 2)
		{
			gx = (int)(base_x + x);
			gy = (int)(base_y + y);
			draw_cell(game,
				MINIMAP_MARGIN + x * game->bonus.minimap_tile,
				MINIMAP_MARGIN + y * game->bonus.minimap_tile,
				read_tile(&game->map, gx, gy));
			x++;
		}
		y++;
	}
}
