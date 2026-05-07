/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_draw.c                                          :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: ngusev <ngusev@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 20:00:00 by ngusev            #+#    #+#             */
/*   Updated: 2026/05/07 20:00:00 by ngusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void	get_stripe(t_ray *ray, int *start, int *end)
{
	int	line_h;

	line_h = (int)(WIN_HEIGHT / ray->perp_dist);
	*start = WIN_HEIGHT / 2 - line_h / 2;
	if (*start < 0)
		*start = 0;
	*end = WIN_HEIGHT / 2 + line_h / 2;
	if (*end >= WIN_HEIGHT)
		*end = WIN_HEIGHT - 1;
}

static int	get_wall_color(t_ray *ray)
{
	if (ray->side == 1)
		return (0x00888888);
	return (0x00FFFFFF);
}

void	draw_column(t_game *game, t_ray *ray, int x)
{
	int	draw_start;
	int	draw_end;
	int	color;
	int	y;

	get_stripe(ray, &draw_start, &draw_end);
	color = get_wall_color(ray);
	y = draw_start;
	while (y <= draw_end)
	{
		put_pixel(&game->screen, x, y, color);
		y++;
	}
}
