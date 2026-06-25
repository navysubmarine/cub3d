/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_p_structs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 17:59:19 by marthoma          #+#    #+#             */
/*   Updated: 2026/06/25 16:29:47 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_tx_info_struct(t_parse *p)
{
	p->textures[NO] = (t_tx_info){"NO", "North", NULL, FALSE};
	p->textures[SO] = (t_tx_info){"SO", "South", NULL, FALSE};
	p->textures[WE] = (t_tx_info){"WE", "West", NULL, FALSE};
	p->textures[EA] = (t_tx_info){"EA", "East", NULL, FALSE};
}

static void	init_col_info_struct(t_parse *p)
{
	p->colors[0] = (t_col_info){"F", "Floor", {-1, -1, -1}, FALSE};
	p->colors[1] = (t_col_info){"C", "Ceiling", {-1, -1, -1}, FALSE};
}

void	init_context_struct(t_parse_context *data, t_parse *p)
{
	data->i = 0;
	data->i_map = 0;
	data->ret_map = 0;
	data->nb_l = p->nb_of_lines;
}

void	init_parsing_struct(t_parse *p)
{
	ft_memset(p, 0, sizeof(t_parse));
	ft_memset(&p->map, 0, sizeof(t_map));
	init_tx_info_struct(p);
	init_col_info_struct(p);
	p->map.is_map_set = FALSE;
}
