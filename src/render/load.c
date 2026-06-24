/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 15:03:06 by marthoma          #+#    #+#             */
/*   Updated: 2026/06/24 18:21:23 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_background_colors(t_game *g)
{
	int	x;
	int	y;

	y = 0;
	while (y < g->win_height)
	{
		x = 0;
		while (x < g->win_width)
		{
			if (y < g->win_height / 2)
				put_pixel(x, y, g->ceiling, g);
			else
				put_pixel(x, y, g->floor, g);
			x++;
		}
		y++;
	}
}

void	load_tex_data(void *img, t_tx_data *data)
{
	data->width = BLOCK_SIZE;
	data->height = BLOCK_SIZE;
	data->addr = mlx_get_data_addr(img, &data->bpp, &data->line_length,
			&data->endian);
}

static void	load_textures(t_game *g)
{
	load_tex_data(g->i.n_wall, &g->i.n_data);
	load_tex_data(g->i.s_wall, &g->i.s_data);
	load_tex_data(g->i.e_wall, &g->i.e_data);
	load_tex_data(g->i.w_wall, &g->i.w_data);
}

static void	load_one_sprite(t_game *g, void **dst, char *path, char *err)
{
	int	dim;

	dim = BLOCK_SIZE;
	*dst = mlx_xpm_file_to_image(g->mlx, path, &dim, &dim);
	if (!*dst)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd(err, 2);
		exit_game(g, 1);
	}
}

void	load_wall_sprites(t_game *g)
{
	load_one_sprite(g, &g->i.n_wall, g->path_no_tx,
		"Northern sprite not loaded\n");
	load_one_sprite(g, &g->i.s_wall, g->path_so_tx,
		"Southern sprite not loaded\n");
	load_one_sprite(g, &g->i.e_wall, g->path_ea_tx,
		"Eastern sprite not loaded\n");
	load_one_sprite(g, &g->i.w_wall, g->path_we_tx,
		"Western sprite not loaded\n");
	load_textures(g);
}
