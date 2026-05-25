/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_aux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngusev <ngusev@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 13:29:12 by ngusev            #+#    #+#             */
/*   Updated: 2026/05/08 13:29:16 by ngusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player_coords(t_game *game, int x, int y, char c)
{
	game->player.pos_x = x + 0.5;
	game->player.pos_y = y + 0.5;
	game->player.dir_x = (c == 'E') - (c == 'W');
	game->player.dir_y = (c == 'S') - (c == 'N');
	game->player.plane_x = 0.66 * ((c == 'N') - (c == 'S'));
	game->player.plane_y = 0.66 * ((c == 'E') - (c == 'W'));
	game->map.grid[y][x] = '0';
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
			if (ft_strchr("NSEW", c))
				return (init_player_coords(game, x, y, c));
			x++;
		}
		y++;
	}
}
