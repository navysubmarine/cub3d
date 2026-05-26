/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 15:35:33 by marthoma          #+#    #+#             */
/*   Updated: 2026/05/26 16:57:01 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	print_file(t_file *file)
{
	int	i;

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
	printf("--- content (%d lines) ---\n", file->nb_of_lines);
	while (file->content && file->content[i])
	{
		printf("  [%d]: %s\n", i, file->content[i]);
		i++;
	}
	i = 0;
	printf("--- map ---\n");
	while (file->map && file->map[i])
	{
		printf("  [%d]: %s\n", i, file->map[i]);
		i++;
	}
	printf("=====================\n");
}