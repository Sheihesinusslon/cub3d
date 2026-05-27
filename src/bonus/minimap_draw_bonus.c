/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_draw_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngusev <ngusev@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 00:00:00 by ngusev            #+#    #+#             */
/*   Updated: 2026/05/18 00:00:00 by ngusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_player_marker(t_game *game, int center_x, int center_y)
{
	int	i;
	int	tile;
	int	len;

	tile = game->bonus.minimap_tile;
	i = -2;
	while (i <= 2)
	{
		put_pixel(&game->screen, center_x + i, center_y, MINIMAP_PLAYER_COLOR);
		put_pixel(&game->screen, center_x, center_y + i, MINIMAP_PLAYER_COLOR);
		i++;
	}
	len = tile * 2;
	i = 1;
	while (i <= len)
	{
		put_pixel(&game->screen,
			center_x + (int)(game->player.dir_x * i),
			center_y + (int)(game->player.dir_y * i),
			MINIMAP_DIR_COLOR);
		i++;
	}
}

static void	draw_minimap_tiles(t_game *game)
{
	int		origin_x;
	int		origin_y;
	double	base_x;
	double	base_y;
	int		radius;

	radius = game->bonus.minimap_radius * game->bonus.minimap_tile;
	origin_x = MINIMAP_MARGIN;
	origin_y = MINIMAP_MARGIN;
	base_x = game->player.pos_x - game->bonus.minimap_radius;
	base_y = game->player.pos_y - game->bonus.minimap_radius;
	draw_minimap_background_bonus(game, origin_x, origin_y);
	draw_minimap_rows_bonus(game, base_x, base_y);
	draw_player_marker(game,
		origin_x + radius,
		origin_y + radius);
}

void	render_minimap_bonus(t_game *game)
{
	if (game->bonus.minimap_tile <= 0 || game->bonus.minimap_radius <= 0)
		return ;
	draw_minimap_tiles(game);
}
