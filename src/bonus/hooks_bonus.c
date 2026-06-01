/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarques <jmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 11:59:30 by jmarques          #+#    #+#             */
/*   Updated: 2026/05/19 11:59:32 by jmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mouse_click(int button, int x, int y, t_game *game)
{
	(void)button;
	(void)x;
	(void)y;
	game->bonus.mouse_enable = !game->bonus.mouse_enable;
	return (0);
}

int	focus_in(t_game *game)
{
	game->bonus.mouse_focused = 1;
	return (0);
}

int	focus_out(t_game *game)
{
	game->bonus.mouse_focused = 0;
	return (0);
}

int	mouse_move(int x, int y, t_game *game)
{
	(void)y;
	if (!game->bonus.mouse_focused || !game->bonus.mouse_enable)
		return (0);
	game->bonus.mouse_delta += x - WIN_WIDTH / 2;
	if (game->bonus.mouse_delta > 50)
		game->bonus.mouse_delta = 50;
	if (game->bonus.mouse_delta < -50)
		game->bonus.mouse_delta = -50;
	return (0);
}
