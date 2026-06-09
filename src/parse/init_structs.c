/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 14:19:14 by marthoma          #+#    #+#             */
/*   Updated: 2026/06/09 14:49:01 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void	init_file_info_struct(t_game *g)
{
	g->file.floor_set = FALSE;
	g->file.ceiling_set = FALSE;
}

static void	init_tx_info_struct(t_game *g)
{
	g->textures[0] = (t_tx_info){"NO", "North", &g->file.path_no};
	g->textures[1] = (t_tx_info){"SO", "South", &g->file.path_so};
	g->textures[2] = (t_tx_info){"WE", "West", &g->file.path_we};
	g->textures[3] = (t_tx_info){"EA", "East", &g->file.path_ea};
}

static void	init_col_info_struct(t_game *g)
{
	g->colors[0] = (t_col_info)
	{"F", "Floor", g->file.floor, &g->file.floor_set};
	g->colors[1] = (t_col_info)
	{"C", "Ceiling", g->file.ceiling, &g->file.ceiling_set};
}

void	init_structs(t_game *g)
{
	ft_memset(g, 0, sizeof(t_game));
	init_tx_info_struct(g);
	init_col_info_struct(g);
	init_file_info_struct(g);
	g->map.is_map_set = FALSE;
}
