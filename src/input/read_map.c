#include "../../cub3d.h"

static int read_texures(int fd, t_map *map)
{
    char *line;
    int cnt = 4;
    while (cnt > 0)
    {
        line = get_next_line(fd);
        if (!line)
            return (-1);
        if (ft_strncmp(line, "NO ", 3) == 0)
            map->no_tex = ft_strdup(line + 3);
        else if (ft_strncmp(line, "SO ", 3) == 0)
            map->so_tex = ft_strdup(line + 3);
        else if (ft_strncmp(line, "WE ", 3) == 0)
            map->we_tex = ft_strdup(line + 3);
        else if (ft_strncmp(line, "EA ", 3) == 0)
            map->ea_tex = ft_strdup(line + 3);
        else
            return (free(line), -1);
        free(line);
        cnt--;
    }
    if (check_textures(map) < 0)
        return (free(line), -1);
}

static int *parse_color(char *str)
{
    int *color;
    char **components;
    int i;

    color = malloc(3 * sizeof(int));
    if (!color)
        return (NULL);
    components = ft_split(str, ',');
    if (!components)
        return (free(color), NULL);
    i = 0;
    while (components[i] && i < 3)
    {
        color[i] = ft_atoi(components[i]);
        free(components[i]);
        i++;
    }
    free(components);
    if (i != 3 || check_color(color) < 0)
        return (free(color), NULL);
    return (color);
}

static int read_colors(int fd, t_map *map)
{
    char *line;
    int cnt = 2;
    while (cnt > 0)
    {
        line = get_next_line(fd);
        if (!line)
            return (-1);
        if (ft_strncmp(line, "F ", 2) == 0)
            map->floor_color = parse_color(line + 2);
        else if (ft_strncmp(line, "C ", 2) == 0)
            map->ceil_color = parse_color(line + 2);
        else
            return (free(line), -1);
        free(line);
        cnt--;
    }
    if (!map->floor_color || !map->ceil_color)
            return (free(line), -1);
}

static int read_grid(int fd, t_map *map)
{
    char *line;
    int h;
    int w;

    h = 0;
    w = 0;
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break;
        if (ft_strlen(line) > w)
            w = ft_strlen(line);
        map->grid[h] = ft_strdup(line);
        if (!map->grid[h])
            return (free(line), -1);
        free(line);
        h++;
    }
    map->height = h;
    map->width = w;
    if (check_grid(map) < 0)
        return -1;
    return (0);
}

int read_map(char *filename)
{
    int fd;
    t_map map;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return (-1);
    if (read_textures(fd, &map) < 0)
        return (free_map(&map), close(fd), -1);
    if (read_colors(fd, &map) < 0)
        return (free_map(&map), close(fd), -1);
    if (read_grid(fd, &map) < 0)
        return (free_map(&map), close(fd), -1);
    close(fd);
    return (0);
}