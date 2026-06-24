/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rendering_structs.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 14:27:21 by marthoma          #+#    #+#             */
/*   Updated: 2026/06/24 18:00:14 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_mlx_struct(t_game *g)
{
	g->mlx = mlx_init();
	mlx_get_screen_size(g->mlx, &g->win_width, &g->win_height);
	g->win = mlx_new_window(g->mlx, g->win_width, g->win_height, "cub3d");
	g->img = mlx_new_image(g->mlx, g->win_width, g->win_height);
	g->addr = mlx_get_data_addr(g->img, &g->bpp, &g->line_length, &g->endian);
	load_wall_sprites(g);
}

void	init_game_struct(t_game *g)
{
	ft_memset(g, 0, sizeof(t_game));
	init_parsing_struct(&g->p);
}
