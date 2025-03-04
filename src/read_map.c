/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idahhan <idahhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:09:57 by idahhan           #+#    #+#             */
/*   Updated: 2025/03/04 12:52:34 by idahhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "so_long.h"

void	read_map(t_map *map)
{
	int		fd;
	char	*tmp;
	char	*line;

	map->height = 0;
	map->file = NULL;
	fd = open(map->filename, O_RDONLY);
	if (fd < 0)
		error_file();
	line = get_next_line(fd);
	while (line)
	{
		tmp = map->file;
		map->file = ft_strjoin(map->file, line);
		free(tmp);
		free(line);
		if (!(map->file))
			ft_free_exit(map);
		map->height++;
		line = get_next_line(fd);
	}
	close(fd);
	map->grid = ft_split(map->file, '\n');
	map->copy = ft_split(map->file, '\n');
	if (!map->grid || !map->copy)
		ft_free_exit(map);
	free(map->file);
}
