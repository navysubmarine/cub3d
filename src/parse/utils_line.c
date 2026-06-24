/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 17:46:04 by marthoma          #+#    #+#             */
/*   Updated: 2026/06/24 17:46:31 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	blank_line_detector(char *line)
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

int	rgb_to_int(int r, int g, int b)
{
	int	color;

	color = r << 16;
	color += g << 8;
	color += b;
	return (color);
}
