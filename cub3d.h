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

# define WIN_WIDTH	1280
# define WIN_HEIGHT	720
# define WIN_TITLE	"cub3D"

# define ERR_USAGE	"Usage: ./cub3d <map.cub>\n"
# define ERR_MAP	"Error\nInvalid map file.\n"

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
	int		*floor_color;
	int		*ceil_color;
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
int		read_map(char *filename);
void	free_map(t_map *map);

// Input checks
int		check_map(t_map *map);
int		check_color(int *color);
int		check_textures(t_map *map);

#endif
