/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idahhan <idahhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:36:35 by idahhan           #+#    #+#             */
/*   Updated: 2025/03/10 08:39:20 by idahhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "so_long.h"

void	file_to_img(t_map *map)
{
	int	px_img;

	px_img = IMG_PXL;
	map->img.wall = mlx_xpm_file_to_image(map->mlx, "imgs/wall.xpm", &px_img,
			&px_img);
	map->img.empty = mlx_xpm_file_to_image(map->mlx, "imgs/empty.xpm", &px_img,
			&px_img);
	map->img.player_right = mlx_xpm_file_to_image(map->mlx,
			"imgs/player_right.xpm", &px_img, &px_img);
	map->img.player_left = mlx_xpm_file_to_image(map->mlx,
			"imgs/player_left.xpm", &px_img, &px_img);
	map->img.exit = mlx_xpm_file_to_image(map->mlx, "imgs/exit.xpm", &px_img,
			&px_img);
	map->img.collectible = mlx_xpm_file_to_image(map->mlx,
			"imgs/collectible.xpm", &px_img, &px_img);
	if (!map->img.wall || !map->img.empty || !map->img.player_right
		|| !map->img.player_left || !map->img.exit || !map->img.collectible)
	{
		write(2, "Error\nImage is not valid\n", 25);
		mlx_destroy_window(map->mlx, map->wind);
		exit(EXIT_FAILURE);
	}
}
