/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 11:47:36 by marthoma          #+#    #+#             */
/*   Updated: 2026/06/03 16:24:52 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

/*TODO: check the file content is valid*/

int	blank_line_detector(char	*line)
{
	int	i;

	i = 0;
	if (line[0] == '\0' || line[0] == '\n')
		return (TRUE);
	while (line[i] == ' ' || line[i] == '\t')
	{
		i++;
	}
	if (line[i] == '\0' || line[i] == '\n')
		return (TRUE);
	else
		return (FALSE);
}

int	calculate_map_len(char **lines, int i, t_game *g)
{
	int	j;

	j = 0;
	while (lines[i + j] && lines[i + j][0] != '\n')
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