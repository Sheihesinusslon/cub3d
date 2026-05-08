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

int	render(t_game *game)
{
	clear_image(&game->screen);
	render_background(game);
	cast_rays(game);
	mlx_put_image_to_window(game->mlx, game->win, game->screen.img, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (ft_printf(ERR_USAGE), 1);
	ft_bzero(&game, sizeof(t_game));
	if (read_map(&game, argv[1]) < 0)
		return (1);
	if (init_window(&game) < 0)
		return (free_map(&game), 1);
	setup_hooks(&game);
	if (!init_textures(&game))
		return (1);
	mlx_loop_hook(game.mlx, render, &game);
	mlx_loop(game.mlx);
	cleanup_game(&game);
	return (0);
}
