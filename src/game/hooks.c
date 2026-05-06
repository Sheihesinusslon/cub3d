/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngusev <ngusev@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 00:00:00 by ngusev            #+#    #+#             */
/*   Updated: 2026/05/04 00:00:00 by ngusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		mlx_loop_end(game->mlx);
	return (0);
}

static int	handle_close(t_game *game)
{
	mlx_loop_end(game->mlx);
	return (0);
}

void	setup_hooks(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, handle_keypress, game);
	mlx_hook(game->win, 17, 0L, handle_close, game);
}
