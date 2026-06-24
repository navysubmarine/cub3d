/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 16:27:31 by marthoma          #+#    #+#             */
/*   Updated: 2026/06/24 17:40:26 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	calculate_map_len(char **lines, int i, t_parse *p)
{
	int	j;

	j = 0;
	while (lines[i + j] && lines[i + j][0] != '\n' && lines[i + j][0] != '\0')
		j++;
	p->map.map_h = j;
	if (p->map.map_h <= 0)
	{
		ft_putstr_fd("Error\nMap doesn't exist\n", 2);
		return (1);
	}
	return (0);
}

int	init_map(char **lines, t_parse *p, int i)
{
	if (calculate_map_len(lines, i, p))
		return (1);
	p->map.map = ft_calloc(p->map.map_h + 1, sizeof(char *));
	if (!p->map.map)
	{
		ft_putstr_fd("Error\nMalloc map failed\n", 2);
		return (1);
	}
	p->map.valid = TRUE;
	return (0);
}

void	store_map_line(t_parse *p, char *line, int i)
{
	p->map.map[i] = ft_strdup(line);
}

static void	assign_angle(t_parse *p, char c)
{
	if (c == 'N')
		p->player.angle = NORTH;
	else if (c == 'S')
		p->player.angle = SOUTH;
	else if (c == 'W')
		p->player.angle = WEST;
	else
		p->player.angle = EAST;
}

void	find_player(t_parse *p, char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	p->player.x = -1;
	p->player.y = -1;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
				|| map[i][j] == 'W')
			{
				p->player.x = j;
				p->player.y = i;
				assign_angle(p, map[i][j]);
				return ;
			}
			j++;
		}
		i++;
	}
}
