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

static int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		handle_close(game);
	else if (keycode == KEY_W)
		move_player(game, 1, 0);
	else if (keycode == KEY_S)
		move_player(game, -1, 0);
	else if (keycode == KEY_A)
		move_player(game, 0, -1);
	else if (keycode == KEY_D)
		move_player(game, 0, 1);
	else if (keycode == KEY_LEFT)
		rotate_player(game, -ROT_SPEED);
	else if (keycode == KEY_RIGHT)
		rotate_player(game, ROT_SPEED);
	game->needs_redraw = true;
	return (0);
}

static int	mouse_move(int x, int y, t_game *game)
{
	static int	last_x = -1;
	double		angle;

	(void)y;
	if (last_x == -1)
		last_x = x;
	angle = (x - last_x) * 0.005;
	rotate_player(game, angle);
	last_x = x;
	game->needs_redraw = true;
	return (0);
}

void	setup_hooks(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, handle_keypress, game);
	mlx_hook(game->win, 17, 0L, handle_close, game);
	mlx_hook(game->win, 6, 1L << 6, mouse_move, game);
}
