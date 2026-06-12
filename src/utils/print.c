/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 15:35:33 by marthoma          #+#    #+#             */
/*   Updated: 2026/06/12 16:18:31 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_parse(t_game *g)
{
	int			i;
	t_parse		*p;
	t_map		*map;
	t_player	*player;

	p = &g->p;
	map = &g->p.map;
	player = &g->p.player;
	i = 0;
	printf("=== PARSE CONTENTS ===\n");
	printf("nb_of_lines: %d\n", p->nb_of_lines);
	printf("--- textures ---\n");
	printf("NO path: %s\n",
		p->textures[NO].path ? p->textures[NO].path : "(null)");
	printf("SO path: %s\n",
		p->textures[SO].path ? p->textures[SO].path : "(null)");
	printf("WE path: %s\n",
		p->textures[WE].path ? p->textures[WE].path : "(null)");
	printf("EA path: %s\n",
		p->textures[EA].path ? p->textures[EA].path : "(null)");
	printf("NO is_set: %d\n", p->textures[NO].is_set);
	printf("SO is_set: %d\n", p->textures[SO].is_set);
	printf("WE is_set: %d\n", p->textures[WE].is_set);
	printf("EA is_set: %d\n", p->textures[EA].is_set);
	printf("--- colors ---\n");
	printf("F  is_set: %d\n", p->colors[0].is_set);
	printf("F  rgb: %d,%d,%d\n", p->colors[0].rgb[0], p->colors[0].rgb[1],
		p->colors[0].rgb[2]);
	printf("C  is_set: %d\n", p->colors[1].is_set);
	printf("C  rgb: %d,%d,%d\n", p->colors[1].rgb[0], p->colors[1].rgb[1],
		p->colors[1].rgb[2]);
	printf("--- map ---\n");
	printf("map_h: %d\n", map->map_h);
	printf("is_map_set: %d\n", map->is_map_set);
	printf("valid: %d\n", map->valid);
	printf("--- player ---\n");
	printf("initial position: (%f, %f)\n", player->x,
		player->y);
	printf("current position: (%f, %f)\n", player->x, player->y);
	printf("--- map content (%d lines) ---\n", map->map_h);
	while (map->map && i < map->map_h)
	{
		printf("[%d]: %s\n", i, map->map[i]);
		i++;
	}
	printf("======================\n");
}

void	print_game(t_game *g)
{
	int i;

	i = 0;
	printf("=== GAME CONTENTS ===\n");
	// printf("mlx: %p\n", g->mlx);
	// printf("win: %p\n", g->win);
	// printf("img: %p\n", g->img);
	// printf("addr: %p\n", (void *)g->addr);
	// printf("bpp: %d\n", g->bpp);
	printf("line_length: %d\n", g->line_length);
	printf("endian: %d\n", g->endian);
	printf("win_height: %d\n", g->win_height);
	printf("win_width: %d\n", g->win_width);
	printf("floor: %d\n", g->floor);
	printf("ceiling: %d\n", g->ceiling);
	printf("path_no_tx: %s\n", g->path_no_tx ? g->path_no_tx : "(null)");
	printf("path_so_tx: %s\n", g->path_so_tx ? g->path_so_tx : "(null)");
	printf("path_we_tx: %s\n", g->path_we_tx ? g->path_we_tx : "(null)");
	printf("path_ea_tx: %s\n", g->path_ea_tx ? g->path_ea_tx : "(null)");
	printf("--- map ---\n");
	while (g->map && g->map[i])
	{
		printf("[%d]: %s\n", i, g->map[i]);
		i++;
	}
	//printf("--- parse ---\n");
	//print_parse(g);
	printf("=====================\n");
}