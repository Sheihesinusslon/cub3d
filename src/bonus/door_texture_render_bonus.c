/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_texture_render_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngusev <ngusev@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 00:00:00 by ngusev            #+#    #+#             */
/*   Updated: 2026/05/12 00:00:00 by ngusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_img	*get_door_texture_bonus(t_game *game, t_ray *ray)
{
	char	cell;

	cell = game->map.grid[ray->map_y][ray->map_x];
	if (cell == CHAR_DOOR)
		return (&game->map.door_texture);
	return (NULL);
}
