/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 15:35:33 by marthoma          #+#    #+#             */
/*   Updated: 2026/06/09 15:42:03 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	print_file(t_game *g)
{
	t_file	*file;
	int		i;

	file = &g->file;
	i = 0;
	printf("=== FILE CONTENTS ===\n");
	printf("nb_of_lines: %d\n", file->nb_of_lines);
	printf("path_no: %s\n", file->path_no ? file->path_no : "(null)");
	printf("path_so: %s\n", file->path_so ? file->path_so : "(null)");
	printf("path_we: %s\n", file->path_we ? file->path_we : "(null)");
	printf("path_ea: %s\n", file->path_ea ? file->path_ea : "(null)");
	if (file->floor_set)
		printf("floor: %d,%d,%d\n", file->floor[0], file->floor[1], file->floor[2]);
	else
		printf("floor: (not set)\n");
	if (file->ceiling_set)
		printf("ceiling: %d,%d,%d\n", file->ceiling[0], file->ceiling[1], file->ceiling[2]);
	else
		printf("ceiling: (not set)\n");
	printf("--- map (%d lines) ---\n", g->map.map_h);
	while (g->map.map && i < g->map.map_h)
	{
		printf("  [%d]: %s\n", i, g->map.map[i]);
		i++;
	}
	printf("=====================\n");
}