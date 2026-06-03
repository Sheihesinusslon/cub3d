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

static void	init_mouse_bonus(t_mouse *mouse)
{
	mouse->mouse_delta = 0;
	mouse->mouse_focused = 0;
	mouse->mouse_enable = 0;
	mouse->ignore_next_mouse_event = 0;
}

void	init_bonus_features(t_game *game)
{
	game->bonus.door_reach = DOOR_REACH;
	game->bonus.minimap_tile = MINIMAP_TILE;
	game->bonus.minimap_radius = MINIMAP_RADIUS;
	game->bonus.last_frame = 0;
	game->bonus.fps = 0;
	init_mouse_bonus(&game->bonus.mouse);
}
