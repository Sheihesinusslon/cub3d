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
#include "../../cub3d.h"

void	clear_image(t_img *img)
{
	ft_memset(img->addr, 0, img->line_len * img->height);
}

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr
		+ (y * img->line_len
			+ x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	render_background(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			if (y < WIN_HEIGHT / 2)
				put_pixel(&game->screen, x, y, game->map.ceil_color);
			else
				put_pixel(&game->screen, x, y, game->map.floor_color);
			x++;
		}
		y++;
	}
}
