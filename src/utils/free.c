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

#include "cub3d.h"

static void	destroy_textures(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (game->map.textures[i].img)
			mlx_destroy_image(
				game->mlx,
				game->map.textures[i].img);
		if (game->map.textures[i].path)
			free(game->map.textures[i].path);
		i++;
	}
	if (game->map.door_texture.img)
		mlx_destroy_image(game->mlx, game->map.door_texture.img);
	if (game->map.door_texture.path)
		free(game->map.door_texture.path);
}

void	free_map(t_game *game)
{
	int	i;

	if (game->map.grid)
	{
		i = 0;
		while (i < game->map.height)
			free(game->map.grid[i++]);
		free(game->map.grid);
	}
	destroy_textures(game);
}
