/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idahhan <idahhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:40:55 by idahhan           #+#    #+#             */
/*   Updated: 2025/02/27 17:44:49 by idahhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../mlx/mlx.h"
#include "so_long.h"

void	f(void)
{
	system("lsof -c so_long");
}

void	map_initializer(t_map *map, char **av)
{
	map->filename = av[1];
}

int	main(int ac, char **av)
{
	t_map	map;

	atexit(f);
	if (ac == 2)
	{
		map_initializer(&map, av);
		check_map(&map);
		// void *mlx;
		// void *mlx_win;
		// mlx = mlx_init();
		// mlx_win = mlx_new_window(mlx, 1500, 1000, "so_long");
		// mlx_loop(mlx);
		// free(&map);
	}
	else
		write(2, "Error\nUsage : ./so_long mapfile\n", 32);
}
