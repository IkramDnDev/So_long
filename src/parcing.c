/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idahhan <idahhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:37:26 by idahhan           #+#    #+#             */
/*   Updated: 2025/02/27 17:55:09 by idahhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "so_long.h"

static void	check_file(char *file)
{
	size_t	len;

	len = ft_strlen(file);
	if (file[len - 1] != 'r' || file[len - 2] != 'e' || file[len - 3] != 'b'
		|| file[len - 4] != '.')
	{
		write(2, "Error\nFilename should be a BER extension file\n", 46);
		exit(EXIT_FAILURE);
	}
}

static int	is_rectangle(t_map *map)
{
	int	i;

	if (!map->grid || !map->grid[0])
		return (0);
	map->width = ft_strlen(map->grid[0]);
	i = 0;
	while (map->grid[i])
	{
		if (ft_strlen(map->grid[i]) != map->width)
			return (0);
		i++;
	}
	return (1);
}

static int	check_walls(t_map *map)
{
	size_t	i;
	size_t	j;

	map->height = 0;
	while (map->grid[map->height])
		map->height++;
	map->width = ft_strlen(map->grid[0]);
	i = 0;
	while (i < map->width)
	{
		if (map->grid[0][i] != '1' || map->grid[map->height - 1][i] != '1')
			return (0);
		i++;
	}
	j = 0;
	while (j < map->height)
	{
		if (map->grid[j][0] != '1' || map->grid[j][map->width - 1] != '1')
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
	int	p;
	int	e;
	int	c;

	i = 0;
	p = 0;
	e = 0;
	c = 0;
	while (map->grid[i++])
	{
		j = 0;
		while (map->grid[i][j++])
		{
			if (map->grid[i][j] == 'P')
				p++;
			else if (map->grid[i][j] == 'E')
				e++;
			else if (map->grid[i][j] == 'C')
				c++;
		}
	}
	return (p == 1 && e == 1 && c > 0);
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
	write(1, "map is valid\n", 13);
	ft_free_split(map->copy);
	ft_free_split(map->grid);
}
