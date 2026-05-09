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

#include "../../cub3d.h"

static void	strip_newline(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
}

static int	parse_header_line(t_map *map, char *line)
{
	int	ret;

	ret = parse_texture_line(map, line);
	if (ret != 0)
		return (ret);
	ret = parse_color_line(map, line);
	return (ret);
}

static int	parse_line(t_map *map, char *line, int *map_started)
{
	int	ret;

	if (!*map_started && is_empty_line(line))
		return (0);
	if (!*map_started && is_map_line(line))
		*map_started = 1;
	if (*map_started)
	{
		if (!is_map_line(line))
			return (-1);
		return (map_add_line(map, line));
	}
	ret = parse_header_line(map, line);
	if (ret <= 0)
		return (-1);
	return (0);
}

static int	parse_file(int fd, t_map *map)
{
	char	*line;
	int		map_started;

	map_started = 0;
	line = get_next_line(fd);
	while (line)
	{
		strip_newline(line);
		if (parse_line(map, line, &map_started) < 0)
			return (free(line), -1);
		free(line);
		line = get_next_line(fd);
	}
	if (!map_started)
		return (-1);
	return (0);
}

int	parse_cub_file(int fd, t_map *map)
{
	if (parse_file(fd, map) < 0)
		return (-1);
	if (check_textures(map) < 0)
		return (-1);
	if (map->floor_color == -1 || map->ceil_color == -1)
		return (printf(ERR_COLOR), -1);
	if (check_map(map) < 0)
		return (printf(ERR_MAP), -1);
	return (0);
}
