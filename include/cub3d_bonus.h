/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngusev <ngusev@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 00:00:00 by ngusev            #+#    #+#             */
/*   Updated: 2026/05/12 00:00:00 by ngusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# ifdef BONUS
#  define IS_BONUS	1
# else
#  define IS_BONUS	0
# endif

# include "defines.h"

typedef struct s_img t_img;
typedef struct s_sprite
{
	double	x;
	double	y;
	t_img	*texture;
} t_sprite;

typedef struct s_sprite_draw
{
	double	transform_x;
	double	transform_y;
	int		screen_x;
	int		width;
	int		height;
	int		start_x;
	int		end_x;
	int		start_y;
	int		end_y;
}	t_sprite_draw;

typedef struct s_bonus
{
	double		door_reach;
	int			minimap_tile;
	int			minimap_radius;
	double		last_frame;
	double		fps;
	double		zbuffer[WIN_WIDTH];
	t_sprite	sprite;
}	t_bonus;

#endif
