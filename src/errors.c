/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idahhan <idahhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:07:25 by idahhan           #+#    #+#             */
/*   Updated: 2025/02/27 17:43:26 by idahhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "so_long.h"

void	error_file(void)
{
	write(2, "Error opening file\n", 19);
	exit(EXIT_FAILURE);
}

void	error_wall(t_map *map)
{
	write(2, "Error\nwalls are not valid\n", 26);
	ft_free_split(map->grid);
	ft_free_split(map->copy);
	exit(EXIT_FAILURE);
}

void	error_element(t_map *map)
{
	write(2, "Error\nelements are not valid\n", 29);
	ft_free_split(map->grid);
	ft_free_split(map->copy);
	exit(EXIT_FAILURE);
}

void	error_caracter(t_map *map)
{
	write(2, "Error\ncaracters are not valid\n", 30);
	ft_free_split(map->grid);
	ft_free_split(map->copy);
	exit(EXIT_FAILURE);
}

void	error_rectangle(t_map *map)
{
	write(2, "Error\nmap is not rectangle\n", 27);
	ft_free_split(map->grid);
	ft_free_split(map->copy);
	exit(EXIT_FAILURE);
}
