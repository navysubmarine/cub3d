/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 16:01:22 by marthoma          #+#    #+#             */
/*   Updated: 2026/05/27 16:01:33 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	test_tx_path(char *tx_type, char *path)
{
	int		fd;
	char	*trimmed;

	trimmed = ft_strtrim(path, " \t");
	if (!trimmed)
		return (1);
	fd = open(trimmed, O_RDONLY);
	free(trimmed);
	if (fd < 0)
	{
		printf("Error. %s texture has invalid pathname\n", tx_type);
		return (1);
	}
	close (fd);
	return (0);
}
