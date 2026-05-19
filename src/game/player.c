/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngusev <ngusev@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 13:29:12 by ngusev            #+#    #+#             */
/*   Updated: 2026/05/08 13:29:16 by ngusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	tile_at(t_map *map, int y, int x)
{
	int	len;

	if (y < 0 || y >= map->height || x < 0)
		return ('1');
	len = ft_strlen(map->grid[y]);
	if (x >= len)
		return ('1');
	return (map->grid[y][x]);
}

static int	can_move(t_game *game, int y, int x)
{
	return (is_walkable_tile_bonus(tile_at(&game->map, y, x)));
}

void	move_player(t_game *game, int forward, int strafe)
{
	double	move_x;
	double	move_y;
	int		nx;
	int		ny;

	move_x = (game->player.dir_x * forward
			+ game->player.plane_x * strafe) * 0.1;
	move_y = (game->player.dir_y * forward
			+ game->player.plane_y * strafe) * 0.1;
	nx = (int)(game->player.pos_x + move_x);
	ny = (int)(game->player.pos_y + move_y);
	if (can_move(game, (int)game->player.pos_y, nx))
		game->player.pos_x += move_x;
	if (can_move(game, ny, (int)game->player.pos_x))
		game->player.pos_y += move_y;
}

void	rotate_player(t_game *game, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player.dir_x;
	old_plane_x = game->player.plane_x;
	game->player.dir_x = old_dir_x * cos(angle)
		- game->player.dir_y * sin(angle);
	game->player.dir_y = old_dir_x * sin(angle)
		+ game->player.dir_y * cos(angle);
	game->player.plane_x = old_plane_x * cos(angle)
		- game->player.plane_y * sin(angle);
	game->player.plane_y = old_plane_x * sin(angle)
		+ game->player.plane_y * cos(angle);
}

void	init_player(t_game *game)
{
	int		y;
	int		x;
	char	c;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (game->map.grid[y][x])
		{
			c = game->map.grid[y][x];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
				return (init_player_coords(game, x, y, c));
			x++;
		}
		y++;
	}
}
