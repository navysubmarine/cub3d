/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 15:16:35 by marthoma          #+#    #+#             */
/*   Updated: 2026/06/05 15:33:15 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_valid_map_line(char	*line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '0' && line[i] != '1'
			&& line[i] != 'N' && line[i] != 'S'
			&& line[i] != 'E' && line[i] != 'W'
			&& line[i] != ' ' && line[i] != '\t')
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

char	*ft_strdup_padded(const char *s, int padded_line_len)
{
	int		i;
	char	*new;

	new = malloc(sizeof(char) * (padded_line_len + 1));
	if (new == NULL)
		return (NULL);
	new[0] = '0';
	i = 0;
	while (s[i])
	{
		new[i + 1] = s[i];
		i++;
	}
	while (i < padded_line_len - 1)
	{
		new[i + 1] = '0';
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
	printf("i_map after loop = %d\n", i_map);
	printf("map_h = %d\n", g->map.map_h);
	copy[0] = ft_memset(copy[0], '0', padded_line_len);
	copy[0][padded_line_len] = '\0';
	copy[g->map.map_h + 1] = malloc(sizeof (char) * (padded_line_len + 1));
	if (!copy[g->map.map_h + 1])
		return (free_content(copy), NULL);
	copy[g->map.map_h + 1] = ft_memset(copy[g->map.map_h + 1], '0', padded_line_len);
	copy[g->map.map_h + 1][padded_line_len] = '\0';
	copy[g->map.map_h + 2] = '\0';
	printf("bottom row: %s\n", copy[g->map.map_h + 1]);
	printf("sentinel: %p\n", copy[g->map.map_h + 2]);
	printf("height= %d\n", g->map.map_h);
	return (copy);
}