/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngusev <ngusev@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 19:23:06 by ngusev            #+#    #+#             */
/*   Updated: 2026/05/07 19:23:10 by ngusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= img->width
			|| y < 0 || y >= img->height)
			return ;
	dst = img->addr
		+ (y * img->line_len
			+ x * img->bytes_per_pixel);
	*(unsigned int *)dst = color;
}

void	render_background(t_game *game)
{
	int	*row;
	int	x;
	int	y;
	int	half;

	half = game->screen.height / 2;
	y = 0;
	while (y < half)
	{
		row = (int *)(game->screen.addr + y * game->screen.line_len);
		x = 0;
		while (x < game->screen.width)
			row[x++] = game->map.ceil_color;
		y++;
	}
	while (y < game->screen.height)
	{
		row = (int *)(game->screen.addr + y * game->screen.line_len);
		x = 0;
		while (x < game->screen.width)
			row[x++] = game->map.floor_color;
		y++;
	}
}
