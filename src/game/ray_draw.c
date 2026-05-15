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

#include "cub3d.h"

static double	calculate_wall_x(t_game *game, t_ray *ray)
{
	double	wall_x;

	if (ray->side == 0)
		wall_x = game->player.pos_y + ray->perp_dist * ray->dir_y;
	else
		wall_x = game->player.pos_x + ray->perp_dist * ray->dir_x;
	wall_x -= floor(wall_x);
	return (wall_x);
}

static int	calculate_tex_x(t_ray *ray, t_img *tex, double wall_x)
{
	int	tex_x;

	tex_x = (int)(wall_x * tex->width);
	if (ray->side == 0 && ray->dir_x < 0)
		tex_x = tex->width - tex_x - 1;
	if (ray->side == 1 && ray->dir_y > 0)
		tex_x = tex->width - tex_x - 1;
	return (tex_x);
}

static void	init_texdraw(
	t_game *game,
	t_ray *ray,
	t_texdraw *texdraw)
{
	get_stripe(ray, &texdraw->draw_start, &texdraw->draw_end);
	texdraw->tex = get_texture(game, ray);
	texdraw->wall_x = calculate_wall_x(game, ray);
	texdraw->tex_x = calculate_tex_x(ray, texdraw->tex, texdraw->wall_x);
	texdraw->step = 1.0 * texdraw->tex->height / ray->line_height;
	texdraw->tex_pos = (texdraw->draw_start - game->screen.height / 2
			+ ray->line_height / 2) * texdraw->step;
}

static void	draw_texture_pixels(
	t_game *game,
	t_texdraw *texdraw,
	int x)
{
	int	y;
	int	color;

	y = texdraw->draw_start;
	while (y <= texdraw->draw_end)
	{
		texdraw->tex_y = (int)texdraw->tex_pos;
		texdraw->tex_pos += texdraw->step;
		if (texdraw->tex_y < 0)
			texdraw->tex_y = 0;
		if (texdraw->tex_y >= texdraw->tex->height)
			texdraw->tex_y = texdraw->tex->height - 1;
		color = get_texture_pixel(texdraw->tex, texdraw->tex_x, texdraw->tex_y);
		put_pixel(&game->screen, x, y, color);
		y++;
	}
}

void	draw_column(t_game *game, t_ray *ray, int x)
{
	t_texdraw	texdraw;

	init_texdraw(game, ray, &texdraw);
	draw_texture_pixels(game, &texdraw, x);
}
