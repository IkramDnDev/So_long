/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idahhan <idahhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:58:49 by idahhan           #+#    #+#             */
/*   Updated: 2025/03/03 12:43:09 by idahhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "so_long.h"

static void	type_elem(t_map *map, int x, int y)
{
	int	type;

	type = map->grid[y / IMG_PXL][x / IMG_PXL];
	if (type == 'C' || type == 'P' || type == 'E' || type == '0')
		mlx_put_image_to_window(map->mlx, map->wind, map->img.empty, x, y);
	if (type == 'C')
		mlx_put_image_to_window(map->mlx, map->wind, map->img.collectible, x,
			y);
	else if (type == 'P')
		mlx_put_image_to_window(map->mlx, map->wind, map->img.player, x, y);
	else if (type == 'E')
		mlx_put_image_to_window(map->mlx, map->wind, map->img.exit, x, y);
	else if (type == '1')
		mlx_put_image_to_window(map->mlx, map->wind, map->img.wall, x, y);
}

void	print_map(t_map *map)
{
	int	i;
	int	j;

	j = 0;
	while (j < map->height)
	{
		i = 0;
		while (i < map->width)
		{
			type_elem(map, i * IMG_PXL, j * IMG_PXL);
			i++;
		}
		j++;
	}
}
