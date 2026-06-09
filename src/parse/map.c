/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemouge <bdemouge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 15:16:35 by marthoma          #+#    #+#             */
/*   Updated: 2026/06/09 17:31:24 by bdemouge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_valid_map_line(char	*line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '0' && line[i] != '1'
			&& line[i] != 'N' && line[i] != 'S'
			&& line[i] != 'E' && line[i] != 'W'
			&& line[i] != ' ')
		{
			ft_putstr_fd("Error. Invalid character in map line\n", 2);
			return (1);
		}
		i++;
	}
	return (0);
}

int	map_line_detector(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == '1')
		return (TRUE);
	else
		return (FALSE);
}

int	find_longest_line_len(char **map)
{
	size_t	longest;
	int		i;

	i = 0;
	longest = ft_strlen(map[i]);
	while (map[i])
	{
		if (longest < ft_strlen(map[i]))
			longest = ft_strlen(map[i]);
		i++;
	}
	return (longest);
}

void	are_walls_enclosed(t_map *map, int x, int y, int nb_lines)
{
	if (y < 0 || y >= nb_lines || x < 0 || x >= (int)ft_strlen(map->padded_copy[y]))
		return ;
	if (map->padded_copy[y][x] == '\0' || map->padded_copy[y][x] == '1' || map->padded_copy[y][x] == 'V')
		return ;
	if (map->padded_copy[y][x] == '0' || map->padded_copy[y][x] == 'N' || map->padded_copy[y][x] == 'S'
		|| map->padded_copy[y][x] == 'E' || map->padded_copy[y][x] == 'W')
	{
		map->valid = FALSE;
		map->padded_copy[y][x] = 'V';
		printf("Error. Map walls are not closed\n");
		//print_map(map, "post unsuccessful flood_fill\n");
		return ;
	}
	map->padded_copy[y][x] = 'V';
	are_walls_enclosed(map, x + 1, y, nb_lines);
	are_walls_enclosed(map, x - 1, y, nb_lines);
	are_walls_enclosed(map, x, y + 1, nb_lines);
	are_walls_enclosed(map, x, y - 1, nb_lines);
	return ;
}

int	handle_map(int *i, int *i_map, t_game *g, char **lines)
{
	while (*i < g->file.nb_of_lines
		&& map_line_detector(lines[*i]) == TRUE)
	{
		if (is_valid_map_line(lines[*i]))
			return (1);
		if (g->map.is_map_set == FALSE)
		{
			g->map.is_map_set = TRUE;
			if (init_map(lines, g, *i))
				return (1);
		}
		store_map_line(g, lines[*i], *i_map);
		(*i_map)++;
		(*i)++;
		continue ;
	}
	if (*i < g->file.nb_of_lines
		&& blank_line_detector(lines[*i]) == TRUE)
	{
		//printf("EOF found\n");
		return (2);
	}
	return (0);
}