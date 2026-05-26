/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarques <jmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 12:26:40 by jmarques          #+#    #+#             */
/*   Updated: 2026/05/21 12:26:42 by jmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <sys/time.h>

static double	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec + tv.tv_usec / 1000000.0);
}

void	fps_show(t_game *game)
{
	double			current_time;
	double			delta;
	char			*buffer;
	char			*num;

	current_time = get_time();
	delta = current_time - game->bonus.last_frame;
	game->bonus.fps = game->bonus.fps * 0.9 + (1.0 / delta) * 0.1;
	game->bonus.last_frame = current_time;
	num = ft_itoa((int)game->bonus.fps);
	buffer = ft_strjoin("FPS: ", num);
	mlx_string_put(game->mlx, game->win, 10, 30, 0xFFFFFF, buffer);
	free(buffer);
	free(num);
}
