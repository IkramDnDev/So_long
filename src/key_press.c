/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idahhan <idahhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 10:45:05 by idahhan           #+#    #+#             */
/*   Updated: 2025/03/04 15:17:07 by idahhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "so_long.h"

int	key_press(int touch, t_map *map)
{
	get_pos_player(map);
	if (touch == ESC)
		return (close_map(map));
	else if (map->exit == 1)
		return (0);
	else if (touch == RIGHT)
		right_move(map);
	else if (touch == DOWN)
		down_move(map);
	else if (touch == UP)
		move_up(map);
	else if (touch == LEFT)
		left_move(map);
	return (0);
}
