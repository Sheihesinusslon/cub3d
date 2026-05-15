/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_tiles_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngusev <ngusev@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 00:00:00 by ngusev            #+#    #+#             */
/*   Updated: 2026/05/12 00:00:00 by ngusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_walkable_tile_bonus(char tile)
{
	if (tile == '0' || tile == CHAR_DOOR_OPEN)
		return (1);
	return (0);
}

int	is_solid_tile_bonus(char tile)
{
	if (tile == '1' || tile == CHAR_DOOR)
		return (1);
	return (0);
}
