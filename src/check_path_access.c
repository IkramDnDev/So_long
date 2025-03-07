/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_access.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idahhan <idahhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 10:05:08 by idahhan           #+#    #+#             */
/*   Updated: 2025/03/07 15:19:25 by idahhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "so_long.h"

static void	move_on_paths(int x, int y, t_map *map)
{
	char	elem;

	elem = map->copy[y][x];
	if (elem == 'C')
	{
		map->c_check -= 1;
		map->copy[y][x] = '1';
	}
	else if (elem == 'E')
	{
		map->e_check -= 1;
		map->copy[y][x] = '1';
	}
	else if (elem == '0' || elem == 'P')
		map->copy[y][x] = '1';
	else
		return ;
	move_on_paths(x + 1, y, map);
	move_on_paths(x - 1, y, map);
	move_on_paths(x, y + 1, map);
	move_on_paths(x, y - 1, map);
}

void	check_path_access(t_map *map)
{
	map->c_check = map->c;
	map->e_check = map->e;
	get_pos_player(map);
	move_on_paths(map->player.x, map->player.y, map);
	if (map->c_check != 0 || map->e_check >= map->e)
	{
		write(2, "Error\nNo valid path\n", 20);
		ft_free_split(map->grid);
		ft_free_split(map->copy);
		exit(EXIT_FAILURE);
	}
}
