/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idahhan <idahhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:40:55 by idahhan           #+#    #+#             */
/*   Updated: 2025/02/26 18:07:59 by idahhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"
#include "mlx/mlx.h"

void	ft_free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

void f(){system("leaks so_long");}
int main(int ac, char **av)
{
    // atexit(f);
    if (ac != 2 || !ft_strnstr(av[1], ".ber", ft_strlen(av[1])))
    {
        write(2, "Error\n", 6);
        exit(1);
    }
    t_map *map = malloc(sizeof(t_map));
    map->grid = read_map(av[1]);
    if (!map->grid)
        return(1);
    if(!check_map(map))
        exit(1);
    // void *mlx;
    // void *mlx_win;
    // mlx = mlx_init();
    // mlx_win = mlx_new_window(mlx, 1500, 1000, "so_long");
    // mlx_loop(mlx);
    ft_free_split(map->grid);
}

