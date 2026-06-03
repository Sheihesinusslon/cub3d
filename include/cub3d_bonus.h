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

typedef struct s_mouse
{
	int			mouse_delta;
	int			mouse_focused;
	int			mouse_enable;
	int			ignore_next_mouse_event;
}	t_mouse;

typedef struct s_bonus
{
	double		door_reach;
	int			minimap_tile;
	int			minimap_radius;
	double		last_frame;
	double		fps;
	t_mouse		mouse;
}	t_bonus;

#endif
