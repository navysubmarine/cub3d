/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 16:05:05 by marthoma          #+#    #+#             */
/*   Updated: 2026/05/27 16:05:21 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
