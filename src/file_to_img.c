/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idahhan <idahhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:36:35 by idahhan           #+#    #+#             */
/*   Updated: 2025/03/03 12:41:25 by idahhan          ###   ########.fr       */
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
	map->img.player = mlx_xpm_file_to_image(map->mlx, "imgs/player.xpm",
			&px_img, &px_img);
	map->img.exit = mlx_xpm_file_to_image(map->mlx, "imgs/exit.xpm", &px_img,
			&px_img);
	map->img.collectible = mlx_xpm_file_to_image(map->mlx,
			"imgs/collectible.xpm", &px_img, &px_img);
}
