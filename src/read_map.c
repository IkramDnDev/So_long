/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idahhan <idahhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:09:57 by idahhan           #+#    #+#             */
/*   Updated: 2025/02/27 17:17:22 by idahhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "so_long.h"

void	read_map(t_map *map)
{
	int		fd;
	char	*tmp;
	char	*line;

	fd = open(map->filename, O_RDONLY);
	if (fd < 0)
		error_file();
	map->p_y = 0;
	map->file = NULL;
	line = get_next_line(fd);
	while (line)
	{
		tmp = map->file;
		map->file = ft_strjoin(map->file, line);
		free(tmp);
		free(line);
		if (!(map->file))
			ft_free_exit(map);
		map->p_y++;
		line = get_next_line(fd);
	}
	close(fd);
	map->grid = ft_split(map->file, '\n');
	map->copy = ft_split(map->file, '\n');
	if (!map->grid || !map->copy)
		ft_free_exit(map);
	free(map->file);
}
