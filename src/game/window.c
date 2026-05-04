/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngusev <ngusev@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 00:00:00 by ngusev            #+#    #+#             */
/*   Updated: 2026/05/04 00:00:00 by ngusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	init_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (-1);
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	if (!game->win)
		return (mlx_destroy_display(game->mlx), free(game->mlx), -1);
	return (0);
}

void	cleanup_game(t_game *game)
{
	free_map(&game->map);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}
