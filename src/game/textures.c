/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarques <jmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 14:11:05 by jmarques          #+#    #+#             */
/*   Updated: 2026/05/08 14:11:07 by jmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_stripe(t_ray *ray, int *start, int *end)
{
	ray->line_height = (int)(WIN_HEIGHT / ray->perp_dist);
	*start = WIN_HEIGHT / 2 - ray->line_height / 2;
	if (*start < 0)
		*start = 0;
	*end = WIN_HEIGHT / 2 + ray->line_height / 2;
	if (*end >= WIN_HEIGHT)
		*end = WIN_HEIGHT - 1;
}

static int	init_texture(t_game *game, t_img *tex)
{
	tex->img = mlx_xpm_file_to_image(
			game->mlx,
			tex->path,
			&tex->width,
			&tex->height);
	if (!tex->img)
		return (0);
	tex->addr = mlx_get_data_addr(
			tex->img,
			&tex->bpp,
			&tex->line_len,
			&tex->endian);
	if (!tex->addr)
	{
		mlx_destroy_image(game->mlx, tex->img);
		tex->img = NULL;
		tex->addr = NULL;
		return (0);
	}
	return (1);
}

int	init_textures(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!init_texture(game, &game->map.textures[i]))
			return (0);
		i++;
	}
	if (!init_door_texture_bonus(game))
		return (0);
	return (1);
}

t_img	*get_texture(t_game *game, t_ray *ray)
{
	t_img	*door_tex;

	door_tex = get_door_texture_bonus(game, ray);
	if (door_tex)
		return (door_tex);
	if (ray->side == 0)
	{
		if (ray->dir_x > 0)
			return (&game->map.textures[EAST]);
		return (&game->map.textures[WEST]);
	}
	if (ray->dir_y > 0)
		return (&game->map.textures[SOUTH]);
	return (&game->map.textures[NORTH]);
}

int	get_texture_pixel(t_img *tex, int x, int y)
{
	char	*dst;

	dst = tex->addr + (y * tex->line_len + x * (tex->bpp / 8));
	return (*(unsigned int *)dst);
}
