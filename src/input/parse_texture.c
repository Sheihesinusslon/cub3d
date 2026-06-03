/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarques <jmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 11:43:19 by jmarques          #+#    #+#             */
/*   Updated: 2026/05/12 11:43:21 by jmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_img	*get_texture_ptr(t_map *map, char *line)
{
	if (line[2] != ' ' && line[2] != '\t')
		return (NULL);
	if (!ft_strncmp(line, "NO", 2))
		return (&map->textures[NORTH]);
	if (!ft_strncmp(line, "SO", 2))
		return (&map->textures[SOUTH]);
	if (!ft_strncmp(line, "WE", 2))
		return (&map->textures[WEST]);
	if (!ft_strncmp(line, "EA", 2))
		return (&map->textures[EAST]);
	return (NULL);
}

int	parse_texture_line(t_map *map, char *line)
{
	t_img	*slot;
	char	*path;

	slot = get_texture_ptr(map, line);
	if (!slot)
		return (parse_door_texture_bonus(map, line));
	if (slot->path)
		return (error_message(ERR_DUP_TEXTURE));
	path = skip_spaces(&line[2]);
	if (*path == '\0')
		return (error_message(ERR_TEXTURE));
	slot->path = ft_strdup(path);
	if (!slot->path)
		return (error_message(ERR_MALLOC));
	return (1);
}
