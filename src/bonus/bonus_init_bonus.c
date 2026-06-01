/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_init_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngusev <ngusev@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 00:00:00 by ngusev            #+#    #+#             */
/*   Updated: 2026/05/12 00:00:00 by ngusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_sprite(t_game *game)
{
	game->bonus.sprite.x = 5.5;
	game->bonus.sprite.y = 3.5;
	game->map.sprite_texture.path = "./textures/torch_2.xpm";
	game->bonus.sprite.texture =
		&game->map.sprite_texture;
}

void	init_bonus_features(t_game *game)
{
	game->bonus.door_reach = DOOR_REACH;
	game->bonus.minimap_tile = MINIMAP_TILE;
	game->bonus.minimap_radius = MINIMAP_RADIUS;
	game->bonus.last_frame = 0;
	game->bonus.fps = 0;
	init_sprite(game);
}

