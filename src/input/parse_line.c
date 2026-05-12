/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarques <jmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 11:05:02 by jmarques          #+#    #+#             */
/*   Updated: 2026/05/12 11:05:05 by jmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_header(t_map *map, char *line)
{
	int	ret;

	ret = parse_texture_line(map, line);
	if (ret != 0)
		return (ret);
	ret = parse_color_line(map, line);
	if (ret != 0)
		return (ret);
	return (ft_printf(ERR_IDENTIFIER), -1);
}

int	parse_map_line(t_map *map, char *line)
{
	if (!is_map_line(line))
		return (printf(ERR_MAP_INVALID),-1);
	return (map_add_line(map, line));
}
