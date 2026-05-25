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
	char	tile;

	tile = tile_at(&game->map, y, x);
	if (IS_BONUS)
		return (is_walkable_tile_bonus(tile));
	return (tile == '0');
}

static int	wall_collision(t_game *game, double next_x, double next_y)
{
	if (!can_move(game,
			(int)(next_y - PLAYER_RADIUS),
		(int)(next_x - PLAYER_RADIUS)))
		return (0);
	if (!can_move(game,
			(int)(next_y - PLAYER_RADIUS),
		(int)(next_x + PLAYER_RADIUS)))
		return (0);
	if (!can_move(game,
			(int)(next_y + PLAYER_RADIUS),
		(int)(next_x - PLAYER_RADIUS)))
		return (0);
	if (!can_move(game, (int)(next_y + PLAYER_RADIUS),
		(int)(next_x + PLAYER_RADIUS)))
		return (0);
	return (1);
}

void	move_player(t_game *game, int forward, int strafe)
{
	double	move_x;
	double	move_y;
	double	next_x;
	double	next_y;

	move_x = (game->player.dir_x * forward
			+ game->player.plane_x * strafe) * MOVE_SPEED;
	move_y = (game->player.dir_y * forward
			+ game->player.plane_y * strafe) * MOVE_SPEED;
	next_x = game->player.pos_x + move_x;
	next_y = game->player.pos_y + move_y;
	if (wall_collision(game, next_x, game->player.pos_y))
		game->player.pos_x = next_x;
	if (wall_collision(game, game->player.pos_x, next_y))
		game->player.pos_y = next_y;
}

void	rotate_player(t_game *game, double angle)
{
	double	old_dir_x;
	double	old_plane_x;
	double	cos_a;
	double	sin_a;

	cos_a = cos(angle);
	sin_a = sin(angle);
	old_dir_x = game->player.dir_x;
	old_plane_x = game->player.plane_x;
	game->player.dir_x = old_dir_x * cos_a
		- game->player.dir_y * sin_a;
	game->player.dir_y = old_dir_x * sin_a
		+ game->player.dir_y * cos_a;
	game->player.plane_x = old_plane_x * cos_a
		- game->player.plane_y * sin_a;
	game->player.plane_y = old_plane_x * sin_a
		+ game->player.plane_y * cos_a;
}
