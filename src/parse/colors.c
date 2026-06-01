/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 16:05:05 by marthoma          #+#    #+#             */
/*   Updated: 2026/05/28 11:31:51 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
