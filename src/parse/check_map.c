/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 11:47:36 by marthoma          #+#    #+#             */
/*   Updated: 2026/06/05 17:41:31 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

/*TODO: check the file content is valid*/

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
	return (0);
}

void	find_player(t_game *g, char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	g->player.initial_x = -1;
	g->player.initial_y = -1;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'W' || map[i][j] == 'E')
			{
				g->player.initial_x = j;
				g->player.initial_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	is_there_one_player(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'W' || map[i][j] == 'E')
				count ++;
			j++;
		}
		i++;
	}
	if (count != 1)
		return (1);
	return (0);
}

int	handle_player_pos(t_game *g, char **map)
{
	if (is_there_one_player(map))
	{
		printf("Error. There is not exactly one player\n");
		return (1);
	}
	find_player(g, map);
	// printf("X Player position = %d\n", g->player.initial_x);
	// printf("Y Player position = %d\n", g->player.initial_y);
	return (0);
}

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