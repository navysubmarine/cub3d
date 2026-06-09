/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemouge <bdemouge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 15:36:49 by marthoma          #+#    #+#             */
/*   Updated: 2026/06/09 17:31:24 by bdemouge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**map_copy(char **map)
{
	char	**copy;
	int		i;

	if (!map)
		return (NULL);
	i = 0;
	while (map[i])
		i++;
	copy = malloc(sizeof(*copy) * (i + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (map[i])
	{
		copy[i] = ft_strdup(map[i]);
		if (!(copy[i]))
			return (free_content(copy), NULL);
		i++;
	}
	copy[i] = NULL;
	return (copy);
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
	copy[g->map.map_h + 1]
		= ft_memset(copy[g->map.map_h + 1], 'P', padded_line_len);
	copy[g->map.map_h + 1][padded_line_len] = '\0';
	copy[g->map.map_h + 2] = '\0';
	return (copy);
}