/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 14:19:14 by marthoma          #+#    #+#             */
/*   Updated: 2026/06/11 15:09:49 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_file_info_struct(t_parse *p)
{
	p->file.floor_set = FALSE;
	p->file.ceiling_set = FALSE;
}

static void	init_tx_info_struct(t_parse *p)
{
	p->textures[0] = (t_tx_info){"NO", "North", &p->file.path_no};
	p->textures[1] = (t_tx_info){"SO", "South", &p->file.path_so};
	p->textures[2] = (t_tx_info){"WE", "West", &p->file.path_we};
	p->textures[3] = (t_tx_info){"EA", "East", &p->file.path_ea};
}

static void	init_col_info_struct(t_parse *p)
{
	p->colors[0] = (t_col_info)
	{"F", "Floor", p->file.floor, &p->file.floor_set};
	p->colors[1] = (t_col_info)
	{"C", "Ceiling", p->file.ceiling, &p->file.ceiling_set};
}

void	init_context_struct(t_parse_context *data, t_parse *p)
{
	data->i = 0;
	data->i_map = 0;
	data->ret_map = 0;
	data->nb_l = p->file.nb_of_lines;
}

void	init_parsing_struct(t_parse *p)
{
	init_tx_info_struct(p);
	init_col_info_struct(p);
	init_file_info_struct(p);
	p->map.is_map_set = FALSE;
}

void	init_game_struct(t_game *p)
{
	ft_memset(p, 0, sizeof(t_game));
	init_parsing_struct(&p->p);
	p->mlx = mlx_init();
	mlx_get_screen_size(p->mlx, &p->win_width, &p->win_height);
	p->win = mlx_new_window(p->mlx, p->win_width, p->win_height, "cub3d");
	p->img = mlx_new_image(p->mlx, p->win_width, p->win_height);
	p->addr = mlx_get_data_addr(p->img, &p->bpp, &p->line_length, &p->endian);
}
