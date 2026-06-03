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
		if (game->mlx && game->map.textures[i].img)
			mlx_destroy_image(game->mlx, game->map.textures[i].img);
		free(game->map.textures[i].path);
		game->map.textures[i].img = NULL;
		game->map.textures[i].path = NULL;
		i++;
	}
	if (game->mlx && game->map.door_texture.img)
		mlx_destroy_image(game->mlx, game->map.door_texture.img);
	free(game->map.door_texture.path);
	game->map.door_texture.img = NULL;
	game->map.door_texture.path = NULL;
}

void	cleanup_game(t_game *game)
{
	free_map(game);
	if (game->screen.img)
		mlx_destroy_image(game->mlx, game->screen.img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
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
		game->map.grid = NULL;
		game->map.height = 0;
	}
	destroy_textures(game);
}
