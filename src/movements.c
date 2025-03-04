/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idahhan <idahhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 11:10:10 by idahhan           #+#    #+#             */
/*   Updated: 2025/03/04 15:38:58 by idahhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "so_long.h"

static void	change_coordinate(t_map *map, int x, int y, int direction)
{
	if (direction == DOWN)
		y += 1;
	if (direction == UP)
		y -= 1;
	if (direction == RIGHT)
		x += 1;
	if (direction == LEFT)
		x -= 1;
	if (map->grid[y][x] == 'E' && map->c == 0)
		return (win_game(map));
	if (map->grid[y][x] == 'C')
	{
		map->grid[y][x] = '0';
		map->c--;
	}
}

void	down_move(t_map *map)
{
	int	x;
	int	y;

	x = map->player.x;
	y = map->player.y;
	if (y < map->height && map->grid[y + 1][x] != '1')
	{
		change_coordinate(map, x, y, DOWN);
		if (map->grid[y + 1][x] == 'E' && (map->c != 0 || map->exit == 1))
			return ;
		map->nb_moves++;
		mlx_put_image_to_window(map->mlx, map->wind, map->img.empty, x
			* IMG_PXL, y * IMG_PXL);
		map->grid[y][x] = '0';
		y++;
		mlx_put_image_to_window(map->mlx, map->wind, map->img.empty, x
			* IMG_PXL, y * IMG_PXL);
		mlx_put_image_to_window(map->mlx, map->wind, map->img.player, x
			* IMG_PXL, y * IMG_PXL);
		map->grid[y][x] = 'P';
		print_movements(map);
	}
	map->player.y = y;
}

void	move_up(t_map *map)
{
	int	x;
	int	y;

	x = map->player.x;
	y = map->player.y;
	if (y > 0 && map->grid[y - 1][x] != '1')
	{
		change_coordinate(map, x, y, UP);
		if (map->grid[y - 1][x] == 'E' && (map->c != 0 || map->exit == 1))
			return ;
		map->nb_moves++;
		mlx_put_image_to_window(map->mlx, map->wind, map->img.empty, x
			* IMG_PXL, y * IMG_PXL);
		map->grid[y][x] = '0';
		y--;
		mlx_put_image_to_window(map->mlx, map->wind, map->img.empty, x
			* IMG_PXL, y * IMG_PXL);
		mlx_put_image_to_window(map->mlx, map->wind, map->img.player, x
			* IMG_PXL, y * IMG_PXL);
		map->grid[y][x] = 'P';
		print_movements(map);
	}
	map->player.y = y;
}

void	left_move(t_map *map)
{
	int	x;
	int	y;

	x = map->player.x;
	y = map->player.y;
	if (x > 0 && map->grid[y][x - 1] != '1')
	{
		change_coordinate(map, x, y, RIGHT);
		if (map->grid[y][x - 1] == 'E' && (map->c != 0 || map->exit == 1))
			return ;
		map->nb_moves++;
		mlx_put_image_to_window(map->mlx, map->wind, map->img.empty, x
			* IMG_PXL, y * IMG_PXL);
		map->grid[y][x] = '0';
		x--;
		mlx_put_image_to_window(map->mlx, map->wind, map->img.empty, x
			* IMG_PXL, y * IMG_PXL);
		mlx_put_image_to_window(map->mlx, map->wind, map->img.player, x
			* IMG_PXL, y * IMG_PXL);
		map->grid[y][x] = 'P';
		print_movements(map);
	}
	map->player.x = x;
}

void	right_move(t_map *map)
{
	int	x;
	int	y;

	x = map->player.x;
	y = map->player.y;
	if (x < map->width && map->grid[y][x + 1] != '1')
	{
		change_coordinate(map, x, y, RIGHT);
		if (map->grid[y][x + 1] == 'E' && (map->c != 0 || map->exit == 1))
			return ;
		map->nb_moves++;
		mlx_put_image_to_window(map->mlx, map->wind, map->img.empty, x
			* IMG_PXL, y * IMG_PXL);
		map->grid[y][x] = '0';
		x++;
		mlx_put_image_to_window(map->mlx, map->wind, map->img.empty, x
			* IMG_PXL, y * IMG_PXL);
		mlx_put_image_to_window(map->mlx, map->wind, map->img.player, x
			* IMG_PXL, y * IMG_PXL);
		map->grid[y][x] = 'P';
		print_movements(map);
	}
	map->player.x = x;
}
