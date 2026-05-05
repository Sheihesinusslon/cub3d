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

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (ft_printf(ERR_USAGE), 1);
	ft_bzero(&game, sizeof(t_game));
	if (read_map(&game.map, argv[1]) < 0)
		return (ft_printf(ERR_MAP), 1);
	if (init_window(&game) < 0)
		return (free_map(&game.map), 1);
	setup_hooks(&game);
	// used for testing only; can be removed later
	if (!getenv("CUB3D_TEST"))
		mlx_loop(game.mlx);
	cleanup_game(&game);
	return (0);
}
