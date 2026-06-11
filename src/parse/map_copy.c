/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 15:36:49 by marthoma          #+#    #+#             */
/*   Updated: 2026/06/11 15:51:24 by marthoma         ###   ########.fr       */
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

static char	*make_padding_row(int len)
{
	char	*row;

	row = malloc(sizeof(char) * (len + 1));
	if (!row)
		return (NULL);
	ft_memset(row, 'P', len);
	row[len] = '\0';
	return (row);
}

static int	set_padding_row(char **copy, int idx, int len)
{
	copy[idx] = make_padding_row(len);
	if (!copy[idx])
		return (free_content(copy), 1);
	return (0);
}

char	**map_padded_copy(char **map, t_parse *p)
{
	char	**copy;
	int		padded_len;
	int		padded_h;
	int		i;

	padded_h = p->map.map_h + 2;
	padded_len = find_longest_line_len(map) + 2;
	copy = malloc(sizeof(char *) * (padded_h + 1));
	if (!copy)
		return (NULL);
	if (set_padding_row(copy, 0, padded_len))
		return (NULL);
	i = 0;
	while (map[i])
	{
		copy[i + 1] = ft_strdup_padded(map[i], padded_len);
		if (!copy[i + 1])
			return (free_content(copy), NULL);
		i++;
	}
	if (set_padding_row(copy, padded_h - 1, padded_len))
		return (NULL);
	copy[padded_h] = NULL;
	return (copy);
}
