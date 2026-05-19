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

int	mouse_move(int x, int y, t_game *game)
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
