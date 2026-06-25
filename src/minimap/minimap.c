/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 16:11:00 by bdemouge          #+#    #+#             */
/*   Updated: 2026/06/25 16:44:20 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_in_minimap(int x, int y, t_minimap *minimap)
{
	if (x < minimap->start_x)
		return (false);
	if (x > minimap->start_x + minimap->width)
		return (false);
	if (y < minimap->start_y)
		return (false);
	if (y > minimap->start_y + minimap->height)
		return (false);
	return (true);
}

void	draw_square(int x, int y, int color, t_game *g)
{
	int			i;
	int			j;
	t_minimap	*minimap;

	minimap = &g->minimap;
	i = 0;
	while (i < minimap->blocksize - 1)
	{
		j = 0;
		while (j < minimap->blocksize - 1)
		{
			if (is_in_minimap(x + j, y + i, minimap))
				put_pixel(x + j, y + i, color, g);
			j++;
		}
		i++;
	}
}

void	init_minimap2(t_minimap *minimap, t_player *player, t_game *g)
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
	minimap->pos_x = (player->x / BLOCK_SIZE);
	minimap->pos_y = (player->y / BLOCK_SIZE);
}

void	draw_background(t_minimap *minimap, t_game *g)
{
	int	x;
	int	y;

	y = 0;
	while (y < minimap->height)
	{
		x = 0;
		while (x < minimap->width)
		{
			put_pixel(minimap->start_x + x, minimap->start_y + y, 0x888888, g);
			x++;
		}
		y++;
	}
}

void	draw_line(float start_x, float start_y, float angle, t_game *g)
{
	float	cos_angle;
	float	sin_angle;
	float	x;
	float	y;
	int		line_len;

	cos_angle = cos(angle);
	sin_angle = sin(angle);
	line_len = 0;
	x = 0;
	y = 0;
	while (line_len < 10)
	{
		put_pixel(start_x + x, start_y + y, 0xFFFFFF, g);
		x += cos_angle;
		y += sin_angle;
		line_len++;
	}
}
