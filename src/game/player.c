#include "../../cub3d.h"

char	tile_at(t_map *map, int y, int x)
{
	int	len;

	if (y < 0 || y >= map->height || x < 0)
		return ('0');
	if (x < 0)
		return ('0');
	len = ft_strlen(map->grid[y]);
	if (x >= len)
		return ('1');
	return (map->grid[y][x]);
}

void move_player(t_game *game, int forward, int strafe)
{
	double	move_x;
	double	move_y;

	move_x = (game->player.dir_x * forward + game->player.plane_x * strafe) * 0.1;
	move_y = (game->player.dir_y * forward + game->player.plane_y * strafe) * 0.1;
	if (tile_at(&game->map, (int)(game->player.pos_y), (int)(game->player.pos_x + move_x)) == '0')
		game->player.pos_x += move_x;
	if (tile_at(&game->map, (int)(game->player.pos_y + move_y), (int)(game->player.pos_x)) == '0')
		game->player.pos_y += move_y;
	printf("Player pos: (%.2f, %.2f)\n", game->player.pos_x, game->player.pos_y);
}

void rotate_player(t_game *game, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player.dir_x;
	old_plane_x = game->player.plane_x;
	game->player.dir_x = old_dir_x * cos(angle) - game->player.dir_y * sin(angle);
	game->player.dir_y = old_dir_x * sin(angle) + game->player.dir_y * cos(angle);
	game->player.plane_x = old_plane_x * cos(angle) - game->player.plane_y * sin(angle);
	game->player.plane_y = old_plane_x * sin(angle) + game->player.plane_y * cos(angle);
	printf("Player dir: (%.2f, %.2f)\n", game->player.dir_x, game->player.dir_y);
	printf("Player plane: (%.2f, %.2f)\n", game->player.plane_x, game->player.plane_y);
}

void	init_player(t_game *game)
{
	int	y;
	int	x;
	char	c;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (game->map.grid[y][x])
		{
			c = game->map.grid[y][x];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				game->player.pos_x = x + 0.5;
				game->player.pos_y = y + 0.5;
				if (c == 'N') { game->player.dir_x = 0; game->player.dir_y = -1; game->player.plane_x = 0.66; game->player.plane_y = 0; }
				else if (c == 'S') { game->player.dir_x = 0; game->player.dir_y = 1; game->player.plane_x = -0.66; game->player.plane_y = 0; }
				else if (c == 'E') { game->player.dir_x = 1; game->player.dir_y = 0; game->player.plane_x = 0; game->player.plane_y = 0.66; }
				else { game->player.dir_x = -1; game->player.dir_y = 0; game->player.plane_x = 0; game->player.plane_y = -0.66; }
				game->map.grid[y][x] = '0';
				return ;
			}
			x++;
		}
		y++;
	}
}