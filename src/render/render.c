/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 12:07:49 by marthoma          #+#    #+#             */
/*   Updated: 2026/06/24 14:43:23 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pixel(int x, int y, int color, t_game *g)
{
	char	*dst;

	if (x >= g->win_width || y >= g->win_height || x < 0 || y < 0)
		return ;
	dst = g->addr + (y * g->line_length + x * (g->bpp / 8));
	*(unsigned int *)dst = color;
}

t_tx_data	*get_correct_tex(t_game *g, t_textureid wall_type)
{
	if (wall_type == NO)
		return (&g->i.n_data);
	if (wall_type == SO)
		return (&g->i.s_data);
	if (wall_type == WE)
		return (&g->i.w_data);
	return (&g->i.e_data);
}

int	get_tex_pixel(t_tx_data *tex, int tex_x, int tex_y)
{
	char	*pixel;

	if (tex_x < 0)
		tex_x = 0;
	if (tex_x >= tex->width)
		tex_x = tex->width - 1;
	if (tex_y < 0)
		tex_y = 0;
	if (tex_y >= tex->height)
		tex_y = tex->height - 1;
	pixel = tex->addr + (tex_y * tex->line_length + tex_x * (tex->bpp / 8));
	return (*(unsigned int *)pixel);
}

void	get_tex_column(t_render_context *r, t_tx_data *tex, t_dda_context *d)
{
	r->tex_x = (int)(d->wall_x * tex->width);
	if (r->tex_x < 0)
		r->tex_x = 0;
	if (r->tex_x >= tex->width)
		r->tex_x = tex->width - 1;
	r->step = tex->height / r->wall_height;
	if (r->bottom_y < 0)
		r->tex_pos = -r->bottom_y * r->step;
	else
		r->tex_pos = 0;
	r->screen_y = r->bottom_y;
	if (r->screen_y < 0)
		r->screen_y = 0;
}

void	draw_wall_column(int i, t_game *g, t_textureid wall_type,
	t_dda_context *d)
{
	t_render_context	r;
	t_tx_data			*tex;

	calculate_wall_size(g, d, &r);
	tex = get_correct_tex(g, wall_type);
	get_tex_column(&r, tex, d);
	while (r.screen_y < r.top_y && r.screen_y < g->win_height)
	{
		r.tex_y = (int)r.tex_pos;
		put_pixel(i, r.screen_y, get_tex_pixel(tex, r.tex_x, r.tex_y), g);
		r.tex_pos += r.step;
		r.screen_y++;
	}
}
