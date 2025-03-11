/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_access.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idahhan <idahhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 10:05:08 by idahhan           #+#    #+#             */
/*   Updated: 2025/03/10 08:39:33 by idahhan          ###   ########.fr       */
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
	else if (elem == '0' || elem == 'P')
		map->copy[y][x] = '1';
	else if (elem == '1' || elem == 'E')
		return ;
	move_on_paths(x + 1, y, map);
	move_on_paths(x - 1, y, map);
	move_on_paths(x, y + 1, map);
	move_on_paths(x, y - 1, map);
}

static int	count_walls_around_exit(t_map *map, int x, int y)
{
	int	walls;

	walls = 0;
	if (y > 0 && map->grid[y - 1][x] == '1')
		walls++;
	if (y < map->height - 1 && map->grid[y + 1][x] == '1')
		walls++;
	if (x > 0 && map->grid[y][x - 1] == '1')
		walls++;
	if (x < map->width - 1 && map->grid[y][x + 1] == '1')
		walls++;
	return (walls);
}

static int	is_exit_blocked(t_map *map)
{
	int	x;
	int	y;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if (map->grid[y][x] == 'E' && count_walls_around_exit(map, x,
					y) == 4)
				return (1);
		}
	}
	return (0);
}

static void	check_c_accessible(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->copy[++i])
	{
		j = -1;
		while (map->copy[i][++j])
		{
			if (map->copy[i][j] == 'C' && map->copy[i][j] != '1')
			{
				write(2, "Error\nCollectible is not accessible\n", 36);
				exit(1);
			}
		}
	}
}

void	check_path_access(t_map *map)
{
	map->c_check = map->c;
	map->e_check = map->e;
	get_pos_player(map);
	move_on_paths(map->player.x, map->player.y, map);
	check_c_accessible(map);
	if (map->c_check != 0 || (map->c_check >= 0 && (is_exit_blocked(map))))
	{
		write(2, "Error\nNo valid path\n", 20);
		ft_free_split(map->grid);
		ft_free_split(map->copy);
		exit(EXIT_FAILURE);
	}
}
