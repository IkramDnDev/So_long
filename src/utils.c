/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idahhan <idahhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 11:02:04 by idahhan           #+#    #+#             */
/*   Updated: 2025/03/04 12:44:46 by idahhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "so_long.h"

int	get_map_height(t_map *map)
{
	int	height;

	height = 0;
	while (map->grid[height])
		height++;
	map->height = height;
	return (height);
}

int	get_map_width(t_map *map)
{
	int	width;

	if (!map->grid || !map->grid[0])
		return (0);
	width = ft_strlen(map->grid[0]);
	map->width = width;
	return (width);
}

void	get_pos_player(t_map *map)
{
	map->player.x = 0;
	map->player.y = 0;
	while (map->player.y < map->height)
	{
		while (map->player.x < map->width)
		{
			if (map->grid[map->player.y][map->player.x] == 'P')
				break ;
			map->player.x++;
		}
		if (map->grid[map->player.y][map->player.x] == 'P')
			break ;
		map->player.x = 0;
		map->player.y++;
	}
}
