/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 16:05:05 by marthoma          #+#    #+#             */
/*   Updated: 2026/06/09 15:42:17 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	test_rgb_format(char *content)
{
	int	i;
	int	comma_nb;

	i = 0;
	comma_nb = 0;
	while (content[i])
	{
		while (content[i] == ' ' || content[i] == '\t')
			i++;
		if (content[i] >= '0' && content[i] <= '9')
		{
			while (content[i] >= '0' && content[i] <= '9')
				i++;
		}
		else if (content[i] == ',')
		{
			comma_nb++;
			i++;
		}
		else
			return (1);
	}
	if (comma_nb != 2)
		return (1);
	return (0);
}

int	test_rgb_color(char	*id, char *content)
{
	char	**tab;
	int		i;

	i = 0;
	if (test_rgb_format(content))
		return (printf("Error. %s color of invalid format\n", id), 1);
	tab = ft_split(content, ',');
	if (!tab)
		return (ft_putstr_fd("Error. Ft_split failed\n", 2), 1);
	while (tab[i])
	{
		if (ft_atoi(tab[i]) > 255 || ft_atoi(tab[i]) < 0)
			return (ft_putstr_fd("Error. RGB number is out of bound\n", 2),
				free_content(tab), 1);
		i++;
	}
	if (i != 3)
	{
		ft_putstr_fd("Error. RGB number must have three elements\n", 2);
		free_content(tab);
		return (1);
	}
	free_content(tab);
	return (0);
}

int	store_rgb(int *values, char *content)
{
	char	**tab;
	int		i;

	i = 0;
	tab = ft_split(content, ',');
	if (!tab)
	{
		ft_putstr_fd("Error. Ft_split failed\n", 2);
		return (1);
	}
	while (i < 3)
	{
		values[i] = ft_atoi(tab[i]);
		i++;
	}
	free_content(tab);
	return (0);
}

int	validate_color_line(char *line, t_game *g)
{
	char	*content;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	while (j < 2)
	{
		if (ft_strncmp(line + i, g->colors[j].id, 1) == 0
			&& (line[i + 1]) != '\0')
		{
			content = find_content(line + i, g->colors[j].id);
			if (test_rgb_color(g->colors[j].word, content)
				|| store_rgb(g->colors[j].field, content))
				return (1);
			*g->colors[j].is_set = TRUE;
			return (0);
		}
		j++;
	}
	return (1);
}

/*0=yes it's a color line, 1=no*/
int	color_line_detector(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (ft_strncmp(line + i, "F ", 2) == 0)
		return (TRUE);
	else if (ft_strncmp(line + i, "C ", 2) == 0)
		return (TRUE);
	else
		return (FALSE);
}

// void	init_col_info_struct(t_game *g)
// {
// 	g->colors[0] = (t_col_info)
// 	{"F", "Floor", g->file.floor, &g->file.floor_set};
// 	g->colors[1] = (t_col_info)
// 	{"C", "Ceiling", g->file.ceiling, &g->file.ceiling_set};
// }
