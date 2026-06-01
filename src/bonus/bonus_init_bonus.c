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

void	init_bonus_features(t_game *game)
{
	game->bonus.door_reach = DOOR_REACH;
	game->bonus.minimap_tile = MINIMAP_TILE;
	game->bonus.minimap_radius = MINIMAP_RADIUS;
	game->bonus.last_frame = 0;
	game->bonus.fps = 0;
	game->bonus.mouse_delta = 0;
	game->bonus.mouse_focused = 0;
	game->bonus.mouse_enable = 0;
}
