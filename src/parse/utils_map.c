/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemouge <bdemouge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 16:27:31 by marthoma          #+#    #+#             */
/*   Updated: 2026/06/10 18:57:54 by bdemouge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_map(char **map, char *name)
{
	int	i;

	i = 0;
	printf("%s\n", name);
	printf("_________________\n");
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}

int	calculate_map_len(char **lines, int i, t_game *g)
{
	int	j;

	j = 0;
	while (lines[i + j] && lines[i + j][0] != '\n' && lines[i + j][0] != '\0')
		j++;
	g->map.map_h = j;
	if (g->map.map_h <= 0)
	{
		ft_putstr_fd("Error. Map doesn't exist\n", 2);
		return (1);
	}
	return (0);
}

int	init_map(char **lines, t_game *g, int i)
{
	if (calculate_map_len(lines, i, g))
		return (1);
	g->map.map = ft_calloc(g->map.map_h + 1, sizeof (char *));
	if (!g->map.map)
	{
		ft_putstr_fd("Error. Malloc map failed\n", 2);
		return (1);
	}
	g->map.valid = TRUE;
	return (0);
}

void	store_map_line(t_game *g, char *line, int i)
{
	g->map.map[i] = line;
}
