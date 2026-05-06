/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngusev <ngusev@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 16:30:45 by ngusev            #+#    #+#             */
/*   Updated: 2026/05/05 16:30:48 by ngusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	free_map(t_map *map)
{
	int	i;

	if (map->grid)
	{
		i = 0;
		while (i < map->height)
			free(map->grid[i++]);
		free(map->grid);
	}
	free(map->no_tex);
	free(map->so_tex);
	free(map->we_tex);
	free(map->ea_tex);
}
