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

int	is_solid_tile_bonus(char tile)
{
	return (tile == '1');
}

int	parse_door_texture_bonus(t_map *map, char *line)
{
	(void)map;
	if (ft_strncmp(line, "DO ", 3) == 0 || ft_strncmp(line, "DO\t", 3) == 0)
		return (error_message(ERR_BONUS_MAP));
	return (0);
}

#endif
