/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngusev <ngusev@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 16:25:05 by ngusev            #+#    #+#             */
/*   Updated: 2026/05/05 16:25:08 by ngusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	parse_line(t_map *map, char *line, bool *map_started)
{
	if (!*map_started && is_empty_line(line))
		return (0);
	if (!*map_started && is_map_line(line))
		*map_started = true;
	if (*map_started)
		return (parse_map_line(map, line));
	if (parse_header(map, line) <= 0)
		return (-1);
	return (0);
}

static void	drain_gnl(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
}

static int	parse_loop(int fd, t_map *map, bool *map_started)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		strip_newline(line);
		if (parse_line(map, line, map_started) < 0)
		{
			free(line);
			drain_gnl(fd);
			return (-1);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}

bool	parse_cub_file(int fd, t_map *map)
{
	bool	map_started;

	map_started = false;
	if (parse_loop(fd, map, &map_started) < 0)
		return (false);
	if (!map_started)
		return (printf(ERR_MAP_EMPTY), false);
	if (check_textures(map) < 0)
		return (false);
	if (map->floor_color == -1 || map->ceil_color == -1)
		return (printf(ERR_COLOR), false);
	if (check_map(map) < 0)
		return (false);
	return (true);
}
