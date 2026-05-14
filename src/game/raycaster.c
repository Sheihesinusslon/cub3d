/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngusev <ngusev@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 20:00:00 by ngusev            #+#    #+#             */
/*   Updated: 2026/05/07 20:00:00 by ngusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_ray_dir(t_game *game, t_ray *ray, int x)
{
	double	cam_x;

	cam_x = 2.0 * x / WIN_WIDTH - 1.0;
	ray->dir_x = game->player.dir_x + game->player.plane_x * cam_x;
	ray->dir_y = game->player.dir_y + game->player.plane_y * cam_x;
	ray->map_x = (int)game->player.pos_x;
	ray->map_y = (int)game->player.pos_y;
}

static void	init_dda_x(t_player *p, t_ray *ray)
{
	if (ray->dir_x == 0)
		ray->delta_x = 1e30;
	else
		ray->delta_x = fabs(1.0 / ray->dir_x);
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_x = (p->pos_x - ray->map_x) * ray->delta_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_x = (ray->map_x + 1.0 - p->pos_x) * ray->delta_x;
	}
}

static void	init_dda_y(t_player *p, t_ray *ray)
{
	if (ray->dir_y == 0)
		ray->delta_y = 1e30;
	else
		ray->delta_y = fabs(1.0 / ray->dir_y);
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_y = (p->pos_y - ray->map_y) * ray->delta_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_y = (ray->map_y + 1.0 - p->pos_y) * ray->delta_y;
	}
}

static void	run_dda(t_map *map, t_ray *ray)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (ray->side_x < ray->side_y)
		{
			ray->side_x += ray->delta_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_y += ray->delta_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (ray->map_y < 0 || ray->map_y >= map->height
			|| ray->map_x < 0 || ray->map_x >= map->width)
			break ;
		if (ray->map_x >= (int)ft_strlen(map->grid[ray->map_y]))
			break ;
		if (is_solid_tile_bonus(map->grid[ray->map_y][ray->map_x]))
			hit = 1;
	}
}

void	cast_rays(t_game *game)
{
	t_ray	ray;
	int		x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		init_ray_dir(game, &ray, x);
		init_dda_x(&game->player, &ray);
		init_dda_y(&game->player, &ray);
		run_dda(&game->map, &ray);
		if (ray.side == 0)
			ray.perp_dist = ray.side_x - ray.delta_x;
		else
			ray.perp_dist = ray.side_y - ray.delta_y;
		draw_column(game, &ray, x);
		x++;
	}
}
