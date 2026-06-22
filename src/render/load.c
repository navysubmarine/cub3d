/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 15:03:06 by marthoma          #+#    #+#             */
/*   Updated: 2026/06/22 11:49:45 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_tex_data(void *img, t_tx_data *data, int width, int height)
{
	(void)width;
	(void)height;
	data->width = width;
	data->height = height;
	data->addr = mlx_get_data_addr(img, &data->bpp, &data->line_length,
			&data->endian);
}

void	load_wall_sprites(t_game *g)
{
	int	w;
	int	h;

	printf("load_wall_sprites called\n");
	w = BLOCK_SIZE;
	h = BLOCK_SIZE;
	g->i.n_wall = mlx_xpm_file_to_image(g->mlx, g->path_no_tx, &w, &h);
	if (!g->i.n_wall)
	{
		ft_putstr_fd("Error: Northern wall sprite could not be loaded\n", 2);
		exit_game(g, 1);
	}
	g->i.s_wall = mlx_xpm_file_to_image(g->mlx, g->path_so_tx, &w, &h);
	if (!g->i.s_wall)
	{
		ft_putstr_fd("Error: Southern wall sprite could not be loaded\n", 2);
		exit_game(g, 1);
	}
	g->i.e_wall = mlx_xpm_file_to_image(g->mlx, g->path_ea_tx, &w, &h);
	if (!g->i.e_wall)
	{
		ft_putstr_fd("Error: Eastern wall sprite could not be loaded\n", 2);
		exit_game(g, 1);
	}
	g->i.w_wall = mlx_xpm_file_to_image(g->mlx, g->path_we_tx, &w, &h);
	if (!g->i.w_wall)
	{
		ft_putstr_fd("Error: Western wall sprite could not be loaded\n", 2);
		exit_game(g, 1);
	}
	load_tex_data(g->i.n_wall, &g->i.n_data, w, h);
	load_tex_data(g->i.s_wall, &g->i.s_data, w, h);
	load_tex_data(g->i.e_wall, &g->i.e_data, w, h);
	load_tex_data(g->i.w_wall, &g->i.w_data, w, h);
}
