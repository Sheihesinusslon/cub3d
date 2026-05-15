/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngusev <ngusev@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 00:00:00 by ngusev            #+#    #+#             */
/*   Updated: 2026/05/12 00:00:00 by ngusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#ifndef BONUS

void	init_bonus_features(t_game *game)
{
	(void)game;
}

int	toggle_door_bonus(t_game *game)
{
	(void)game;
	return (0);
}

int	is_walkable_tile_bonus(char tile)
{
	return (tile == '0');
}

int	is_solid_tile_bonus(char tile)
{
	return (tile == '1');
}

#endif
