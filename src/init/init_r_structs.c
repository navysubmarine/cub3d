/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_r_structs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 14:27:21 by marthoma          #+#    #+#             */
/*   Updated: 2026/06/25 17:49:17 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_mlx_struct(t_game *g)
{
	g->mlx = mlx_init();
	if (!g->mlx)
		exit_game(g, 1);
	mlx_get_screen_size(g->mlx, &g->win_width, &g->win_height);
	g->win_height *= 0.9;
	g->win_width *= 0.9;
	g->win = mlx_new_window(g->mlx, g->win_width, g->win_height, "cub3d");
	g->img = mlx_new_image(g->mlx, g->win_width, g->win_height);
	g->addr = mlx_get_data_addr(g->img, &g->bpp, &g->line_length, &g->endian);
	load_wall_sprites(g);
}

void	init_minimap(t_minimap *minimap, t_game *g)
{
	minimap->blocksize = g->win_height / 4 / MINIMAP_HEIGHT;
	minimap->height = minimap->blocksize * MINIMAP_HEIGHT;
	minimap->width = minimap->blocksize * MINIMAP_WIDTH;
	minimap->start_x = 20;
	minimap->start_y = g->win_height - minimap->height - 20;
	minimap->radius_x = minimap->width / 2;
	minimap->radius_y = minimap->height / 2;
	minimap->center_x = minimap->start_x + minimap->radius_x;
	minimap->center_y = minimap->start_y + minimap->radius_y;
}

void	init_game_struct(t_game *g)
{
	ft_memset(g, 0, sizeof(t_game));
	init_parsing_struct(&g->p);
	g->p.g = g;
}
