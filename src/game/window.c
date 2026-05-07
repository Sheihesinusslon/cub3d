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

static int	init_game_screen(t_game *game)
{
	game->screen.img = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!game->screen.img)
		return (-1);
	game->screen.addr = mlx_get_data_addr(
			game->screen.img,
			&game->screen.bpp,
			&game->screen.line_len,
			&game->screen.endian);
	if (!game->screen.addr)
	{
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		return (-1);
	}
	game->screen.height = WIN_HEIGHT;
	game->screen.width = WIN_WIDTH;
	return (0);
}

int	init_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (-1);
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	if (!game->win)
		return (mlx_destroy_display(game->mlx), free(game->mlx), -1);
	if (init_game_screen(game) < 0)
	{
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		return (-1);
	}
	return (0);
}

void	cleanup_game(t_game *game)
{
	free_map(&game->map);
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
