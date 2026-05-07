/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngusev <ngusev@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 19:04:13 by ngusev            #+#    #+#             */
/*   Updated: 2026/04/30 19:04:17 by ngusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <sys/time.h>
# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"
# include "minilibx-linux/mlx.h"
# include <stdio.h>
# include "defines.h"

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
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
	char	*no_tex;
	char	*so_tex;
	char	*we_tex;
	char	*ea_tex;
	int		floor_color;
	int		ceil_color;
}	t_map;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_img		screen;
	t_player	player;
	t_map		map;
}	t_game;

// Map management
int		read_map(t_map *map, char *filename);
void	free_map(t_map *map);
int		parse_cub_file(int fd, t_map *map);

// Parser helpers
int		is_empty_line(char *l);
int		parse_texture_line(t_map *map, char *l);
int		parse_color_line(t_map *map, char *l);
int		is_map_line(char *line);
int		map_add_line(t_map *map, char *line);

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
#endif
