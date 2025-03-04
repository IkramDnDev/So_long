/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idahhan <idahhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:40:55 by idahhan           #+#    #+#             */
/*   Updated: 2025/03/04 15:46:30 by idahhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../mlx/mlx.h"
#include "so_long.h"

void	f(void)
{
	system("leaks so_long");
}

void	map_initializer(t_map *map, char **av)
{
	map->filename = av[1];
	map->c = 0;
	map->e = 0;
	map->p = 0;
	map->nb_moves = 0;
	map->player.x = 0;
	map->player.y = 0;
	map->exit = 0;
}

int	main(int ac, char **av)
{
	t_map	map;

	atexit(f);
	if (ac == 2)
	{
		map_initializer(&map, av);
		check_map(&map);
		map.mlx = mlx_init();
		map.wind = mlx_new_window(map.mlx, map.width * IMG_PXL, map.height
				* IMG_PXL, WND_NAME);
		file_to_img(&map);
		print_map(&map);
		mlx_hook(map.wind, 17, 0, close_map, &map);
		mlx_key_hook(map.wind, key_press, &map);
		mlx_loop(map.mlx);
	}
	write(2, "Error\nUsage : ./so_long mapfile\n", 32);
	exit(EXIT_FAILURE);
}
