/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src/bonus/render_sprite_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarques <jmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 12:26:40 by jmarques          #+#    #+#             */
/*   Updated: 2026/05/29 12:26:42 by jmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_sprite_pos(
	t_game *game,
	t_sprite *sp,
	double *sprite_x,
	double *sprite_y)
{
	*sprite_x = sp->x - game->player.pos_x;
	*sprite_y = sp->y - game->player.pos_y;
}

static void	init_sprite_draw(t_sprite_draw *draw)
{
	if (draw->start_y < 0)
		draw->start_y = 0;
	if (draw->end_y >= WIN_HEIGHT)
		draw->end_y = WIN_HEIGHT - 1;
	draw->screen_x =
		(int)((WIN_WIDTH / 2)
		* (1 + draw->transform_x
		/ draw->transform_y));
	draw->height = abs((int)(WIN_HEIGHT / draw->transform_y));
	draw->width = draw->height;
	draw->start_x = -draw->width / 2 + draw->screen_x;
	draw->end_x = draw->width / 2 + draw->screen_x;
	draw->start_y = WIN_HEIGHT / 2 - draw->height / 2;
	draw->end_y = WIN_HEIGHT / 2 + draw->height / 2;
}

static void	get_sprite_transform(
	t_game *game,
	double sprite_x,
	double sprite_y,
	t_sprite_draw *draw)
{
	double inv_det;
	inv_det = 1.0 /
		(game->player.plane_x * game->player.dir_y
		- game->player.dir_x * game->player.plane_y);
	draw->transform_x = inv_det *
		(game->player.dir_y * sprite_x
		- game->player.dir_x * sprite_y);
	draw->transform_y = inv_det *
		(-game->player.plane_y * sprite_x
		+ game->player.plane_x * sprite_y);
}
static void	draw_sprite_column(
	t_game *game,
	t_sprite *sp,
	t_sprite_draw *draw,
	int stripe)
{
	int	tex_x;
	int	tex_y;
	int	y;
	int	color;

	tex_x = (stripe - draw->start_x) * sp->texture->width / draw->width;

	y = draw->start_y;
	while (y < draw->end_y)
	{
		tex_y = (y - draw->start_y) * sp->texture->height / draw->height;
		color = get_texture_pixel(sp->texture, tex_x, tex_y);
		if (color != 0)
			put_pixel(&game->screen, stripe, y, color);
		y++;
	}
}

static void	draw_sprite(
	t_game *game,
	t_sprite *sp,
	t_sprite_draw *draw)
{
	int stripe;

	stripe = draw->start_x;
	while (stripe < draw->end_x)
	{
		if (stripe >= 0
			&& stripe < WIN_WIDTH
			&& draw->transform_y
			< game->bonus.zbuffer[stripe])
		{
			draw_sprite_column(
				game,
				sp,
				draw,
				stripe);
		}
		stripe++;
	}
}

void	render_sprite(t_game *game, t_sprite *sp)
{
	t_sprite_draw	draw;
	double			sprite_x;
	double			sprite_y;

	get_sprite_pos(
		game,
		sp,
		&sprite_x,
		&sprite_y);
	get_sprite_transform(
		game,
		sprite_x,
		sprite_y,
		&draw);
	if (draw.transform_y <= 0.1)
		return ;
	init_sprite_draw(&draw);
	draw_sprite(
		game,
		sp,
		&draw);
}