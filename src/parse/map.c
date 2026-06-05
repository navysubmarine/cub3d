/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 15:16:35 by marthoma          #+#    #+#             */
/*   Updated: 2026/06/05 17:40:08 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

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

int	are_walls_enclosed(char **map, int x, int y, int nb_lines)
{
	if (y < 0 || y >=  nb_lines || x < 0 || x >= (int)ft_strlen(map[y]))
		return (0);
	if (map[y][x] == '\0' || map[y][x] == '1' || map[y][x] == 'V')
		return (0);
	if (map[y][x] == '0' || map[y][x] == 'N' || map[y][x] == 'S'
		|| map[y][x] == 'E' || map[y][x] == 'W')
	{
		map[y][x] = 'V';
		are_walls_enclosed(map, x + 1, y, nb_lines);
		are_walls_enclosed(map, x - 1, y, nb_lines);
		are_walls_enclosed(map, x, y + 1, nb_lines);
		are_walls_enclosed(map, x, y - 1, nb_lines);
		//print_map(map, "post unsuccessful flood_fill\n");
		return (1);
	}
	map[y][x] = 'V';
	are_walls_enclosed(map, x + 1, y, nb_lines);
	are_walls_enclosed(map, x - 1, y, nb_lines);
	are_walls_enclosed(map, x, y + 1, nb_lines);
	are_walls_enclosed(map, x, y - 1, nb_lines);
	return (0);
}

char	*ft_strdup_padded(const char *s, int padded_line_len)
{
	int		i;
	char	*new;

	new = malloc(sizeof(char) * (padded_line_len + 1));
	if (new == NULL)
		return (NULL);
	new[0] = 'P';
	i = 0;
	while (s[i])
	{
		new[i + 1] = s[i];
		i++;
	}
	while (i < padded_line_len - 1)
	{
		new[i + 1] = 'P';
		i++;
	}
	new[i + 1] = '\0';
	return (new);
}

char	**map_padded_copy(char **map, t_game *g)
{
	char	**copy;
	int		padded_line_len;
	int		padded_map_h;
	int		i_map;

	padded_map_h = g->map.map_h + 2;
	padded_line_len = find_longest_line_len(map) + 2;
	copy = malloc(sizeof(char **) * (padded_map_h + 2));
	if (!copy)
		return (NULL);
	copy[0] = malloc(sizeof (char) * (padded_line_len + 1));
	if (!copy[0])
		return (free_content(copy), NULL);
	i_map = 0;
	while (map[i_map])
	{
		copy[i_map + 1] = ft_strdup_padded(map[i_map], padded_line_len);
		if (!(copy[i_map + 1]))
			return (free_content(copy), NULL);
		i_map++;
	}
	copy[0] = ft_memset(copy[0], 'P', padded_line_len);
	copy[0][padded_line_len] = '\0';
	copy[g->map.map_h + 1] = malloc(sizeof (char) * (padded_line_len + 1));
	if (!copy[g->map.map_h + 1])
		return (free_content(copy), NULL);
	copy[g->map.map_h + 1] = ft_memset(copy[g->map.map_h + 1], 'P', padded_line_len);
	copy[g->map.map_h + 1][padded_line_len] = '\0';
	copy[g->map.map_h + 2] = '\0';
	return (copy);
}