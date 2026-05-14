/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngusev <ngusev@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 16:25:15 by ngusev            #+#    #+#             */
/*   Updated: 2026/05/05 16:25:18 by ngusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	parse_rgb_number(char **ptr)
{
	int	num;

	*ptr = skip_spaces(*ptr);
	if (!ft_isdigit(**ptr))
		return (-1);
	num = 0;
	while (ft_isdigit(**ptr))
	{
		num = (num * 10) + (**ptr - '0');
		if (num > 255)
			return (-1);
		(*ptr)++;
	}
	return (num);
}

static int	parse_rgb_component(char **ptr, int *value, bool comma)
{
	*value = parse_rgb_number(ptr);
	if (*value < 0)
		return (error_message(ERR_COLOR));
	*ptr = skip_spaces(*ptr);
	if (comma && **ptr != ',')
		return (error_message(ERR_COLOR));
	if (comma)
		(*ptr)++;
	return (0);
}

static int	parse_rgb_values(int *rgb, char *value)
{
	char	*ptr;

	ptr = value;
	if (parse_rgb_component(&ptr, &rgb[0], true) < 0)
		return (-1);
	if (parse_rgb_component(&ptr, &rgb[1], true) < 0)
		return (-1);
	if (parse_rgb_component(&ptr, &rgb[2], false) < 0)
		return (-1);
	if (*skip_spaces(ptr) != '\0')
		return (error_message(ERR_COLOR));
	return (0);
}

static int	rgb_to_int(int *rgb)
{
	return ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
}

int	parse_color_line(t_map *map, char *line)
{
	int		*slot;
	int		rgb[3];
	char	*value;

	slot = NULL;
	if ((line[1] == ' ' || line[1] == '\t') && line[0] == 'F')
		slot = &map->floor_color;
	else if ((line[1] == ' ' || line[1] == '\t') && line[0] == 'C')
		slot = &map->ceil_color;
	if (!slot)
		return (0);
	if (*slot != -1)
		return (error_message(ERR_DUP_COLOR));
	value = skip_spaces(&line[1]);
	if (*value == '\0')
		return (error_message(ERR_COLOR));
	if (parse_rgb_values(rgb, value) < 0)
		return (-1);
	*slot = rgb_to_int(rgb);
	return (1);
}
