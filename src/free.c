/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idahhan <idahhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:46:30 by idahhan           #+#    #+#             */
/*   Updated: 2025/02/27 17:16:11 by idahhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "so_long.h"

void	ft_free_exit(t_map *map)
{
	if (map)
	{
		if (map->grid)
			ft_free_split(map->grid);
		if (map->copy)
			ft_free_split(map->copy);
		if (map->file)
			free(map->file);
	}
	exit(EXIT_FAILURE);
}

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
