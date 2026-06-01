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

static void	update_fps(t_game *game)
{
	double			current_time;
	double			delta;
	static int		frames;
	static double	elapsed;

	current_time = get_time();
	delta = current_time - game->bonus.last_frame;
	game->bonus.last_frame = current_time;
	if (delta <= 0.0)
		return ;
	frames++;
	elapsed += delta;
	if (elapsed >= 1.0)
	{
		game->bonus.fps = frames / elapsed;
		frames = 0;
		elapsed = 0.0;
	}
}

void	fps_show(t_game *game)
{
	char	*num;
	char	*buffer;

	update_fps(game);
	num = ft_itoa((int)game->bonus.fps);
	if (!num)
		return ;
	buffer = ft_strjoin("FPS: ", num);
	free(num);
	if (!buffer)
		return ;
	mlx_string_put(game->mlx, game->win, 10, 30, 0xFFFFFF, buffer);
	free(buffer);
}
