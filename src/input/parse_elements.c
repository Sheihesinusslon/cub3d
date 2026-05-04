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
			return (-1);
		num = 0;
		while (ft_isdigit(*ptr))
			num = (num * 10) + (*ptr++ - '0');
		rgb[idx++] = num;
		ptr = skip_spaces(ptr);
		if (idx < 3 && *ptr++ != ',')
			return (-1);
	}
	if (*skip_spaces(ptr) != '\0' || check_color(rgb) < 0)
		return (-1);
	return (0);
}

int	is_empty_line(char *line)
{
	if (!line || line[0] != '\0')
		return (0);
	return (1);
}

int	parse_texture_line(t_map *map, char *line)
{
	char	**slot;
	char	*value;

	slot = NULL;
	if ((line[2] == ' ' || line[2] == '\t') && line[0] == 'N' && line[1] == 'O')
		slot = &map->no_tex;
	else if ((line[2] == ' ' || line[2] == '\t') && line[0] == 'S' && line[1] == 'O')
		slot = &map->so_tex;
	else if ((line[2] == ' ' || line[2] == '\t') && line[0] == 'W' && line[1] == 'E')
		slot = &map->we_tex;
	else if ((line[2] == ' ' || line[2] == '\t') && line[0] == 'E' && line[1] == 'A')
		slot = &map->ea_tex;
	if (!slot)
		return (0);
	if (*slot)
		return (-1);
	value = skip_spaces(line + 2);
	if (*value == '\0')
		return (-1);
	*slot = ft_strdup(value);
	if (!*slot)
		return (-1);
	return (1);
}

int	parse_color_line(t_map *map, char *line)
{
	int		**slot;
	int		rgb[3];
	char	*value;

	slot = NULL;
	if ((line[1] == ' ' || line[1] == '\t') && line[0] == 'F')
		slot = &map->floor_color;
	else if ((line[1] == ' ' || line[1] == '\t') && line[0] == 'C')
		slot = &map->ceil_color;
	if (!slot)
		return (0);
	if (*slot)
		return (-1);
	value = skip_spaces(line + 1);
	if (*value == '\0' || parse_rgb_values(rgb, value) < 0)
		return (-1);
	*slot = malloc(sizeof(int) * 3);
	if (!*slot)
		return (-1);
	(*slot)[0] = rgb[0];
	(*slot)[1] = rgb[1];
	(*slot)[2] = rgb[2];
	return (1);
}
