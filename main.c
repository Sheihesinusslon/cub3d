/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngusev <ngusev@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 19:03:51 by ngusev            #+#    #+#             */
/*   Updated: 2026/04/30 19:03:56 by ngusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf(ERR_USAGE);
		return (1);
	}
	ft_printf("cub3D: map file: %s\n", argv[1]);
	if (read_map(argv[1]) < 0)
	{
		ft_printf(ERR_MAP);
		return (1);
	}
	return (0);
}
