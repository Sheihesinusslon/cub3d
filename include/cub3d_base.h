/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_base.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngusev <ngusev@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 00:00:00 by ngusev            #+#    #+#             */
/*   Updated: 2026/05/12 00:00:00 by ngusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BASE_H
# define CUB3D_BASE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <sys/time.h>
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <stdio.h>
# include "defines.h"

enum e_tex
{
	NORTH,
	SOUTH,
	WEST,
	EAST
};

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
	char	*path;
}	t_img;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	t_img	textures[4];
	t_img	door_texture;
	int		floor_color;
	int		ceil_color;
}	t_map;

typedef struct s_ray
{
	double	dir_x;
	double	dir_y;
	double	delta_x;
	double	delta_y;
	double	side_x;
	double	side_y;
	double	perp_dist;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		side;
	int		line_height;
}	t_ray;

typedef struct s_texdraw
{
	t_img	*tex;
	double	wall_x;
	double	step;
	double	tex_pos;
	int		tex_x;
	int		tex_y;
	int		draw_start;
	int		draw_end;
}	t_texdraw;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_img		screen;
	t_player	player;
	t_map		map;
	t_bonus		bonus;
	bool		needs_redraw;
}	t_game;

// Map management
int		read_map(t_game *game, char *filename);
void	free_map(t_game *game);
bool	parse_cub_file(int fd, t_map *map);

// Parser helpers
int		is_empty_line(char *l);
void	strip_newline(char *line);
int		parse_texture_line(t_map *map, char *l);
int		parse_color_line(t_map *map, char *l);
int		is_map_line(char *line);
int		map_add_line(t_map *map, char *line);
int		parse_map_line(t_map *map, char *line);
int		parse_header(t_map *map, char *line);
char	*skip_spaces(char *str);
int		error_message(const char *str);

// Input checks
int		check_map(t_map *map);
int		check_color(int *color);
int		check_textures(t_map *map);

// Window and game loop
int		init_window(t_game *game);
void	setup_hooks(t_game *game);
void	cleanup_game(t_game *game);

// Player movement
void	move_player(t_game *game, int forward, int strafe);
void	rotate_player(t_game *game, double angle);
void	init_player(t_game *game);
void	init_player_coords(t_game *game, int x, int y, char c);

// Rendering
void	render_background(t_game *game);
void	clear_image(t_img *img);
void	put_pixel(t_img *img, int x, int y, int color);
void	cast_rays(t_game *game);
void	draw_column(t_game *game, t_ray *ray, int x);

// Textures
int		init_textures(t_game *game);
t_img	*get_texture(t_game *game, t_ray *ray);
int		get_texture_pixel(t_img *tex, int x, int y);
void	get_stripe(t_ray *ray, int *start, int *end);

// Bonus hooks
void	init_bonus_features(t_game *game);
int		toggle_door_bonus(t_game *game);
int		is_walkable_tile_bonus(char tile);
int		is_solid_tile_bonus(char tile);
int		parse_door_texture_bonus(t_map *map, char *line);
int		check_door_texture_bonus(t_map *map);
int		init_door_texture_bonus(t_game *game);
t_img	*get_door_texture_bonus(t_game *game, t_ray *ray);

#endif
