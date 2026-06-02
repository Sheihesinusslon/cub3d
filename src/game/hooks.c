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
	return (0);
}

static void	set_key_state(t_game *game, int keycode, int state)
{
	if (keycode == KEY_W)
		game->keys.w = state;
	else if (keycode == KEY_S)
		game->keys.s = state;
	else if (keycode == KEY_A)
		game->keys.a = state;
	else if (keycode == KEY_D)
		game->keys.d = state;
	else if (keycode == KEY_LEFT)
		game->keys.left = state;
	else if (keycode == KEY_RIGHT)
		game->keys.right = state;
}

static int	key_release(int keycode, t_game *game)
{
	set_key_state(game, keycode, 0);
	return (0);
}

static int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		return (handle_close(game));
	if (IS_BONUS && keycode == KEY_E)
		toggle_door_bonus(game);
	set_key_state(game, keycode, 1);
	return (0);
}

void	setup_hooks(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, handle_keypress, game);
	mlx_hook(game->win, 3, 1L << 1, key_release, game);
	mlx_hook(game->win, 17, 0L, handle_close, game);
	if (IS_BONUS)
	{
		mlx_hook(game->win, 6, 1L << 6, mouse_move, game);
		mlx_hook(game->win, 9, 1L << 21, focus_in, game);
		mlx_hook(game->win, 10, 1L << 21, focus_out, game);
		mlx_hook(game->win, 4, 1L << 2, mouse_click, game);
	}
}
