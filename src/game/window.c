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

#include "cub3d.h"

static int	init_img(t_game *game, t_img *screen)
{
	screen->img = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!screen->img)
		return (-1);
	screen->addr = mlx_get_data_addr(
			screen->img,
			&screen->bpp,
			&screen->line_len,
			&screen->endian);
	if (!screen->addr)
		return (-1);
	screen->bytes_per_pixel = screen->bpp / BITS_IN_BYTE;
	screen->height = WIN_HEIGHT;
	screen->width = WIN_WIDTH;
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
	if (init_img(game, &game->screen) < 0)
		return (cleanup_game(game), -1);
	return (0);
}
