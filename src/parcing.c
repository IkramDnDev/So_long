/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idahhan <idahhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:37:26 by idahhan           #+#    #+#             */
/*   Updated: 2025/03/07 12:00:37 by idahhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "so_long.h"

static int	is_rectangle(t_map *map)
{
	int		i;
	size_t	width;

	if (!map->grid || !map->grid[0])
		return (0);
	width = ft_strlen(map->grid[0]);
	i = 0;
	while (map->grid[i])
	{
		if (ft_strlen(map->grid[i]) != width)
			return (0);
		i++;
	}
	return (1);
}

static int	check_walls(t_map *map)
{
	size_t	i;
	size_t	j;
	size_t	width;
	size_t	height;

	height = get_map_height(map);
	width = get_map_width(map);
	i = 0;
	while (i < width)
	{
		if (map->grid[0][i] != '1' || map->grid[height - 1][i] != '1')
			return (0);
		i++;
	}
	j = 0;
	while (j < height)
	{
		if (map->grid[j][0] != '1' || map->grid[j][width - 1] != '1')
			return (0);
		j++;
	}
	return (1);
}

static int	check_caracters(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->grid[i])
	{
		j = 0;
		while (map->grid[i][j])
		{
			if (map->grid[i][j] != '0' && map->grid[i][j] != '1'
				&& map->grid[i][j] != 'P' && map->grid[i][j] != 'C'
				&& map->grid[i][j] != 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_elements(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->grid[++i])
	{
		j = -1;
		while (map->grid[i][++j])
		{
			if (map->grid[i][j] == 'P')
				map->p++;
			else if (map->grid[i][j] == 'E')
				map->e++;
			else if (map->grid[i][j] == 'C')
				map->c++;
		}
	}
	if (map->p != 1 || map->e != 1 || map->c <= 0)
		return (0);
	return (1);
}

void	check_map(t_map *map)
{
	check_file(map->filename);
	read_map(map);
	if (!is_rectangle(map))
		error_rectangle(map);
	if (!check_walls(map))
		error_wall(map);
	if (!check_elements(map))
		error_element(map);
	if (!check_caracters(map))
		error_caracter(map);
	check_path_access(map);
	ft_free_split(map->copy);
}
