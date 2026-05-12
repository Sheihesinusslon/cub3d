/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_texture_render_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngusev <ngusev@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 00:00:00 by ngusev            #+#    #+#             */
/*   Updated: 2026/05/12 00:00:00 by ngusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_door_texture_bonus(t_game *game)
{
	t_img	*tex;

	if (!IS_BONUS)
		return (1);
	tex = &game->map.door_texture;
	tex->img = mlx_xpm_file_to_image(game->mlx, tex->path, &tex->width, &tex->height);
	if (!tex->img)
		return (0);
	tex->addr = mlx_get_data_addr(tex->img, &tex->bpp, &tex->line_len, &tex->endian);
	if (!tex->addr)
		return (0);
	return (1);
}

t_img	*get_door_texture_bonus(t_game *game, t_ray *ray)
{
	char	cell;

	if (!IS_BONUS)
		return (NULL);
	cell = game->map.grid[ray->map_y][ray->map_x];
	if (cell == 'D')
		return (&game->map.door_texture);
	return (NULL);
}
