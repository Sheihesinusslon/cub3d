#include "../../cub3d.h"

int check_map(t_map *map)
{
    return (1);
}

int check_color(int *color)
{
    if (color[0] < 0 || color[0] > 255 || color[1] < 0 || color[1] > 255 || color[2] < 0 || color[2] > 255)
        return (-1);
    return (0);
}

int check_textures(t_map *map)
{
    if (!map->no_tex || !map->so_tex || !map->we_tex || !map->ea_tex)
        return (-1);
    return (0);
}
