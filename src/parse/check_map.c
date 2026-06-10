/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 11:47:36 by marthoma          #+#    #+#             */
/*   Updated: 2026/06/10 15:40:38 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

/*TODO: check the file content is valid*/

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

int	is_player_on_edge(t_game *g, char **map)
{
	int		x;
	int		y;

	x = g->player.initial_x;
	y = g->player.initial_y;
	if (x == 0 || y == 0 || y == g->map.map_h - 1)
		return (1);
	if (map[y][x - 1] == ' ')
		return (1);
	if (map[y][x + 1] == ' ' || map[y][x + 1] == '\0')
		return (1);
	if (x >= (int)ft_strlen(map[y - 1]) || map[y - 1][x] == ' '
		|| map[y - 1][x] == '\0')
		return (1);
	if (x >= (int)ft_strlen(map[y + 1])
		|| map[y + 1][x] == ' ' || map[y + 1][x] == '\0')
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
	if (is_player_on_edge(g, map))
	{
		printf("Error. The player is on the edge\n");
		return (1);
	}
	// printf("X Player position = %d\n", g->player.initial_x);
	// printf("Y Player position = %d\n", g->player.initial_y);
	return (0);
}

int	is_map_playable(t_game *g)
{
	g->map.copy = map_copy(g->map.map);
	if (!g->map.copy)
	{
		ft_putstr_fd("Error. Map couldn't be copied\n", 2);
		return (1);
	}
	// print_map(copy, "copy");
	g->map.padded_copy = map_padded_copy(g->map.map, g);
	if (!g->map.padded_copy)
	{
		ft_putstr_fd("Error. Padded map couldn't be copied\n", 2);
		return (1);
	}
	// print_map(padded_copy, "padded copy");
	if (handle_player_pos(g, g->map.copy))
		return (1);
	are_walls_enclosed(&g->map, 0, 0, g->map.map_h + 2);
	are_there_still_spaces(&g->map);
	if (g->map.valid == FALSE)
		return (1);
	else
		printf("Congrats !! Your map has no holes\n");
	return (0);
}

int	are_there_still_spaces(t_map *map)
{
	int	i;

	i = 0;
	while (map->padded_copy[i])
	{
		if (ft_strchr(map->padded_copy[i], ' '))
		{
			map->valid = FALSE;
			return (1);
		}
		i++;
	}
	return (0);
}
