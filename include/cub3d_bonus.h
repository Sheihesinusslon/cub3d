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

typedef struct s_bonus
{
	double		door_reach;
	int			minimap_tile;
	int			minimap_radius;
	double		last_frame;
	double		fps;
	int			mouse_delta;
	int			mouse_focused;
	int			mouse_enable;
}	t_bonus;

#endif
