/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarques <jmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 10:20:27 by jmarques          #+#    #+#             */
/*   Updated: 2026/05/12 10:20:32 by jmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define WIN_WIDTH	1280
# define WIN_HEIGHT	720
# define WIN_TITLE	"cub3D"
# define KEY_ESC	65307
# define KEY_W		119
# define KEY_A		97
# define KEY_S		115
# define KEY_D		100
# define KEY_E		101
# define KEY_LEFT	65361
# define KEY_RIGHT	65363
# define ROT_SPEED	0.05
# define DOOR_REACH	1.6

# define ERR_USAGE			"Usage: ./cub3d <map.cub>\n"
# define ERR_MAP			"Error\nInvalid map file.\n"
# define ERR_ARGC			"Error\nInvalid number of arguments\n"
# define ERR_EXTENSION		"Error\nInvalid file extension (.cub required)\n"
# define ERR_FILE         	"Error\nCannot open file\n"
# define ERR_MAP_EMPTY    	"Error\nEmpty map\n"
# define ERR_MAP_INVALID  	"Error\nInvalid map\n"
# define ERR_MAP_OPEN     	"Error\nMap is not closed\n"
# define ERR_PLAYER       	"Error\nInvalid player position\n"
# define ERR_PLAYER_NUMBER 	"Error\nMore than one player\n"
# define ERR_TEXTURE		"Error\nTexture loading failed\n"
# define ERR_TEXTURE_XPM	"Error\nTexture path incorrect\n"
# define ERR_TEXTURE_PATH	"Error\nTexture file not found\n"
# define ERR_COLOR			"Error\nInvalid RGB color\n"
# define ERR_MEMORY			"Error\nMemory allocation failed\n"
# define ERR_DUPLICATE		"Error\nDuplicate identifier\n"
# define ERR_IDENTIFIER		"Error\nMissing identifier\n"
# define ERR_MALLOC			"Error\nMalloc failed\n"
# define ERR_DUP_TEXTURE	"Error\nDuplicate texture\n"
# define ERR_DUP_COLOR		"Error\nDuplicate color definition\n"
# define ERR_INV_IDENTIFIER	"Error\nTexture identifier incorrect\n"
#endif
