/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idahhan <idahhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:37:26 by idahhan           #+#    #+#             */
/*   Updated: 2025/02/26 18:09:46 by idahhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "so_long.h"

char **read_map(const char *filename)
{
    int fd;
    int i;
    char *line;
    char **map;

    i = 0;
    fd = open(filename, O_RDONLY, 0644);
    if (fd < 0)
    {
        write(2, "Problem in open file\n", 21);
        return(NULL);
    }
    map = malloc(100 * sizeof(char *));
    if (!map)
    {
        close(fd);
        return(NULL);
    }   
    while ((line = get_next_line(fd)))
    {
        if (line[ft_strlen(line) - 1] == '\n')
            line[ft_strlen(line) - 1] = '\0';
        map[i++] = line;
    }
    map[i] = NULL;
    close(fd);
    return(map);
}

static int is_rectangle(char **map)
{
    int i;
    size_t width;

    width = ft_strlen(map[0]);
    i = 0;
    while(map[i])
    {
        if (ft_strlen(map[i])!= width)
            return(0);
        i++;
    }
    return(1);
}

static int check_walls(char **map)
{
    int i;
    int j;
    int width;
    int height;
    
    height = 0;
    while(map[height])
        height++;
    width = ft_strlen(map[0]);
    i = 0;
    while(i < width)
    {
        if (map[0][i] != '1' || map[height - 1][i] != '1')
            return(0);
        i++;
    }
    j = 0;
    while(j < height)
    {
        if (map[j][0] != '1' || map[j][width - 1] != '1')
            return(0);
        j++;
    }
    return(1);
}

static int check_caracters(char **map)
{
    int i;
    int j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while(map[i][j])
        {
            if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'P' && map[i][j] != 'C' && map[i][j] != 'E')
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

static int check_elements(char **map)
{
    int i;
    int j;
    int p;
    int e;
    int c;

    i = 0;
    p = 0;
    e = 0;
    c = 0;
    while(map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'P')
                p++;
            else if(map[i][j] == 'E')
                e++;
            else if(map[i][j] == 'C')
                c++;
            j++;
        }
        i++;
    }
    if (p != 1 || e != 1 || c < 1)
        return (0);
    return (1);
}

int check_map(t_map *map)
{
    // if (!is_rectangle(map->grid) || !check_walls(map->grid) || !check_elements(map->grid) || !check_caracters(map->grid))
    //     return (0);
    if (!is_rectangle(map->grid))
    {
        write(2, "map is not rectangle\n", 21);
        return (0);
    }
    if (!check_walls(map->grid))
    {
        write(2, "walls are not valid\n", 20);
        return (0);
    }
    if (!check_elements(map->grid))
    {
        write(2, "elements are not valid\n", 23);
        return (0);
    }
    if (!check_caracters(map->grid))
    {
        write(2, "caracters are not valid\n", 24);
        return (0);
    }
    return(1);
}
