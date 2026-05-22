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

#include "cub3d.h"

static int	handle_close(t_game *game)
{
	mlx_loop_end(game->mlx);
	cleanup_game(game);
	exit (0);
	return (0);
}

static int	key_release(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->keys.w = 0;
	else if (keycode == KEY_S)
		game->keys.s = 0;
	else if (keycode == KEY_A)
		game->keys.a = 0;
	else if (keycode == KEY_D)
		game->keys.d = 0;
	else if (keycode == KEY_LEFT)
		game->keys.left = 0;
	else if (keycode == KEY_RIGHT)
		game->keys.right = 0;
	return (0);
}

static int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		handle_close(game);
	else if (keycode == KEY_W)
		game->keys.w = 1;
	else if (keycode == KEY_S)
		game->keys.s = 1;
	else if (keycode == KEY_A)
		game->keys.a = 1;
	else if (keycode == KEY_D)
		game->keys.d = 1;
	else if (IS_BONUS && keycode == KEY_E)
		toggle_door_bonus(game);
	else if (keycode == KEY_LEFT)
		game->keys.left = 1;
	else if (keycode == KEY_RIGHT)
		game->keys.right = 1;
	return (0);
}

void	setup_hooks(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, handle_keypress, game);
	mlx_hook(game->win, 3, 1L << 1, key_release, game);
	mlx_hook(game->win, 17, 0L, handle_close, game);
	if (IS_BONUS)
		mlx_hook(game->win, 6, 1L << 6, mouse_move, game);
}
