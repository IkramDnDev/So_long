/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idahhan <idahhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:41:10 by idahhan           #+#    #+#             */
/*   Updated: 2025/03/08 12:49:43 by idahhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define IMG_PXL 50
# define DOWN 1
# define UP 13
# define RIGHT 2
# define LEFT 0
# define ESC 53
# define TITLE "so_long"

typedef struct s_player
{
	int			x;
	int			y;
	int			direction;
}				t_player;

typedef struct s_img
{
	void		*empty;
	void		*wall;
	void		*collectible;
	void		*exit;
	void		*player_right;
	void		*player_left;
}				t_img;

typedef struct s_map
{
	char		**grid;
	char		**copy;
	char		*file;
	char		*filename;
	int			width;
	int			height;
	int			e;
	int			c;
	int			p;
	int			c_check;
	int			e_check;
	int			nb_moves;
	int			exit;
	void		*mlx;
	void		*wind;
	t_img		img;
	t_player	player;
}				t_map;

int				get_map_width(t_map *map);
int				get_map_height(t_map *map);
int				close_map(t_map *map);
int				key_press(int touch, t_map *map);

char			*get_next_line(int fd);

void			read_map(t_map *map);
void			check_map(t_map *map);
void			get_pos_player(t_map *map);
void			check_path_access(t_map *map);
void			file_to_img(t_map *map);
void			print_map(t_map *map);
void			win_game(t_map *map);
void			print_movements(t_map *map);
void			check_file(char *file);
void			change_coordinate(t_map *map, int x, int y, int direction);
void			check_direction(t_map *map, int x, int y);

// movements
void			right_move(t_map *map);
void			down_move(t_map *map);
void			move_up(t_map *map);
void			left_move(t_map *map);

// free
void			ft_free_split(char **split);
void			ft_free_exit(t_map *map);

// error
void			error_file(void);
void			error_wall(t_map *map);
void			error_element(t_map *map);
void			error_caracter(t_map *map);
void			error_rectangle(t_map *map);
#endif
