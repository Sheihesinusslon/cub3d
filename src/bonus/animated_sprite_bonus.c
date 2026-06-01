/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src/bonus/animated_sprite_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarques <jmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 12:26:40 by jmarques          #+#    #+#             */
/*   Updated: 2026/05/29 12:26:42 by jmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int get_torch_frame(void)
{
	struct timeval	tv;
	long			ms;

	gettimeofday(&tv, NULL);
	ms = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return ((ms / 150) % 4);
}