/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 16:27:31 by marthoma          #+#    #+#             */
/*   Updated: 2026/06/12 16:21:15 by marthoma         ###   ########.fr       */
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

int	calculate_map_len(char **lines, int i, t_parse *p)
{
	int	j;

	j = 0;
	while (lines[i + j] && lines[i + j][0] != '\n' && lines[i + j][0] != '\0')
		j++;
	p->map.map_h = j;
	if (p->map.map_h <= 0)
	{
		ft_putstr_fd("Error. Map doesn't exist\n", 2);
		return (1);
	}
	return (0);
}

int	init_map(char **lines, t_parse *p, int i)
{
	if (calculate_map_len(lines, i, p))
		return (1);
	p->map.map = ft_calloc(p->map.map_h + 1, sizeof (char *));
	if (!p->map.map)
	{
		ft_putstr_fd("Error. Malloc map failed\n", 2);
		return (1);
	}
	p->map.valid = TRUE;
	return (0);
}

void	store_map_line(t_parse *p, char *line, int i)
{
	p->map.map[i] = ft_strdup(line);
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
			if (map[i][j] == 'N')
			{
				p->player.x = j;
				p->player.y = i;
				p->player.angle = NO;
				return ;
			}
			if (map[i][j] == 'S')
			{
				p->player.x = j;
				p->player.y = i;
				p->player.angle = SO;
				return ;
			}
			if (map[i][j] == 'E')
			{
				p->player.x = j;
				p->player.y = i;
				p->player.angle = EA;
				return ;
			}
			if (map[i][j] == 'W')
			{
				p->player.x = j;
				p->player.y = i;
				p->player.angle = WE;
				return ;
			}
			j++;
		}
		i++;
	}
}
