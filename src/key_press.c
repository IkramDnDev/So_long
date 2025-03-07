/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idahhan <idahhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 10:45:05 by idahhan           #+#    #+#             */
/*   Updated: 2025/03/07 10:08:22 by idahhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "so_long.h"

void	change_coordinate(t_map *map, int x, int y, int direction)
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

int	key_press(int touch, t_map *map)
{
	get_pos_player(map);
	if (touch == ESC)
		return (close_map(map));
	else if (map->exit == 1)
		return (0);
	else if (touch == RIGHT || touch == 124)
		right_move(map);
	else if (touch == DOWN || touch == 125)
		down_move(map);
	else if (touch == UP || touch == 126)
		move_up(map);
	else if (touch == LEFT || touch == 123)
		left_move(map);
	return (0);
}
