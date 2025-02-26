/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idahhan <idahhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:41:10 by idahhan           #+#    #+#             */
/*   Updated: 2025/02/26 17:22:18 by idahhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct s_map
{
    char    **grid;  // La carte sous forme de tableau 2D
    int     width;   // Largeur de la carte
    int     height;  // Hauteur de la carte
    int     player_x; // Position X du joueur
    int     player_y; // Position Y du joueur
}   t_map;

char	*get_next_line(int fd);
char **read_map(const char *filename);
int check_map(t_map *map);
#endif