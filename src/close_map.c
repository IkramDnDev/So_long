/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idahhan <idahhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:22:30 by idahhan           #+#    #+#             */
/*   Updated: 2025/03/04 15:41:41 by idahhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "so_long.h"

int	close_map(t_map *map)
{
	mlx_destroy_window(map->mlx, map->wind);
	ft_free_split(map->grid);
	exit(EXIT_SUCCESS);
	return (0);
}

void	win_game(t_map *map)
{
	map->exit = 1;
	map->nb_moves++;
	mlx_clear_window(map->mlx, map->wind);
	write(1, "you win\n", 8);
}
