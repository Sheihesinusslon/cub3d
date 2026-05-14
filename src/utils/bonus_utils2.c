/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngusev <ngusev@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 00:00:00 by ngusev            #+#    #+#             */
/*   Updated: 2026/05/12 00:00:00 by ngusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#ifndef BONUS

int	parse_door_texture_bonus(t_map *map, char *line)
{
	(void)map;
	(void)line;
	return (0);
}

int	check_door_texture_bonus(t_map *map)
{
	(void)map;
	return (0);
}

int	init_door_texture_bonus(t_game *game)
{
	(void)game;
	return (1);
}

t_img	*get_door_texture_bonus(t_game *game, t_ray *ray)
{
	(void)game;
	(void)ray;
	return (NULL);
}

#endif
