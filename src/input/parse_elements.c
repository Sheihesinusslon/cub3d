/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngusev <ngusev@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 16:25:15 by ngusev            #+#    #+#             */
/*   Updated: 2026/05/05 16:25:18 by ngusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static char	*skip_spaces(char *str)
{
	while (*str == ' ' || *str == '\t')
		str++;
	return (str);
}

static int	parse_rgb_values(int *rgb, char *value)
{
	int		idx;
	int		num;
	char	*ptr;

	idx = 0;
	ptr = value;
	while (idx < 3)
	{
		ptr = skip_spaces(ptr);
		if (!ft_isdigit(*ptr))
			return (ft_printf(ERR_COLOR), -1);
		num = 0;
		while (ft_isdigit(*ptr))
			num = (num * 10) + (*ptr++ - '0');
		rgb[idx++] = num;
		ptr = skip_spaces(ptr);
		if (idx < 3 && *ptr++ != ',')
			return (ft_printf(ERR_COLOR), -1);
	}
	if (*skip_spaces(ptr) != '\0' || check_color(rgb) < 0)
		return (ft_printf(ERR_COLOR), -1);
	return (0);
}

static int	pack_rgb(int *rgb)
{
	return ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
}

int	parse_texture_line(t_map *map, char *l)
{
	char	**slot;
	char	*value;

	slot = NULL;
	if ((l[2] == ' ' || l[2] == '\t') && l[0] == 'N' && l[1] == 'O')
		slot = &map->no_tex;
	else if ((l[2] == ' ' || l[2] == '\t') && l[0] == 'S' && l[1] == 'O')
		slot = &map->so_tex;
	else if ((l[2] == ' ' || l[2] == '\t') && l[0] == 'W' && l[1] == 'E')
		slot = &map->we_tex;
	else if ((l[2] == ' ' || l[2] == '\t') && l[0] == 'E' && l[1] == 'A')
		slot = &map->ea_tex;
	if (!slot)
		return (0);
	if (*slot)
		return (ft_printf(ERR_DUPLICATE), -1);
	value = skip_spaces(l + 2);
	if (*value == '\0')
		return (ft_printf(ERR_TEXTURE), -1);
	*slot = ft_strdup(value);
	if (!*slot)
		return (ft_printf(ERR_TEXTURE), -1);
	return (1);
}

int	parse_color_line(t_map *map, char *l)
{
	int		*slot;
	int		rgb[3];
	char	*value;

	slot = NULL;
	if ((l[1] == ' ' || l[1] == '\t') && l[0] == 'F')
		slot = &map->floor_color;
	else if ((l[1] == ' ' || l[1] == '\t') && l[0] == 'C')
		slot = &map->ceil_color;
	if (!slot)
		return (0);
	if (*slot != -1)
		return (ft_printf(ERR_COLOR), -1);
	value = skip_spaces(l + 1);
	if (*value == '\0' || parse_rgb_values(rgb, value) < 0)
		return (ft_printf(ERR_COLOR), -1);
	*slot = pack_rgb(rgb);
	return (1);
}
