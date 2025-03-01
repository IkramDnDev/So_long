/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idahhan <idahhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:41:10 by idahhan           #+#    #+#             */
/*   Updated: 2025/03/01 12:20:16 by idahhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_map
{
	char	**grid;
	char	**copy;
	char	*file;
	char	*filename;
	int		width;
	int		height;
	int		e;
	int		c;
	int		p;
	int		p_x;
	int		p_y;
	int		c_check;
	int		e_check;
}			t_map;

char		*get_next_line(int fd);
void		read_map(t_map *map);
void		check_map(t_map *map);
int			get_map_width(t_map *map);
int			get_map_height(t_map *map);
void		get_pos_player(t_map *map);
void		check_path_access(t_map *map);

// free
void		ft_free_split(char **split);
void		ft_free_exit(t_map *map);

// error
void		error_file(void);
void		error_wall(t_map *map);
void		error_element(t_map *map);
void		error_caracter(t_map *map);
void		error_rectangle(t_map *map);
#endif
