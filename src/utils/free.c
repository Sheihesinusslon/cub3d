#include "../../cub3d.h"

void free_map(t_map *map)
{
    int i;

    if (map->grid)
    {
        i = 0;
        while (i < map->height)
            free(map->grid[i++]);
        free(map->grid);
    }
    if (map->no_tex)
        free(map->no_tex);
    if (map->so_tex)
        free(map->so_tex);
    if (map->we_tex)
        free(map->we_tex);
    if (map->ea_tex)
        free(map->ea_tex);
    if (map->floor_color)
        free(map->floor_color);
    if (map->ceil_color)
        free(map->ceil_color);
}