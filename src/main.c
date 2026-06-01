/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngusev <ngusev@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 19:03:51 by ngusev            #+#    #+#             */
/*   Updated: 2026/04/30 19:03:56 by ngusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_frame(t_game *game)
{
	render_background(game);
	cast_rays(game);
	if (IS_BONUS)
	{
		fps_show(game);
		render_minimap_bonus(game);
		if (game->bonus.mouse_delta)
		{
			rotate_player(game, game->bonus.mouse_delta * MOVE_ROOT);
			game->bonus.mouse_delta = 0;
		}
		if (game->bonus.mouse_focused && game->bonus.mouse_enable)
			mlx_mouse_move(game->mlx, game->win,
				WIN_WIDTH / 2, WIN_HEIGHT / 2);
	}
	mlx_put_image_to_window(game->mlx, game->win, game->screen.img, 0, 0);
}

static int	game_loop(t_game *game)
{
	int	forward;
	int	strafe;

	forward = game->keys.w - game->keys.s;
	strafe = game->keys.d - game->keys.a;
	if (forward || strafe)
		move_player(game, forward, strafe);
	if (game->keys.left)
		rotate_player(game, -ROT_SPEED);
	if (game->keys.right)
		rotate_player(game, ROT_SPEED);
	draw_frame(game);
	return (0);
}

static int	init_game(t_game *game, char *map)
{
	if (read_map(game, map) < 0)
		return (1);
	if (init_window(game) < 0)
		return (free_map(game), 1);
	init_player(game);
	if (IS_BONUS)
		init_bonus_features(game);
	if (!init_textures(game))
		return (cleanup_game(game), 1);
	setup_hooks(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (printf(ERR_USAGE), 1);
	ft_bzero(&game, sizeof(t_game));
	if (init_game(&game, argv[1]))
		return (1);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
