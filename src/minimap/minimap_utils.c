/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 16:33:39 by marthoma          #+#    #+#             */
/*   Updated: 2026/06/25 16:47:29 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_player(t_minimap *minimap, t_game *g)
{
	int	x;
	int	y;

	x = 0;
	while (x < 3)
	{
		y = 0;
		while (y < 3)
		{
			put_pixel(minimap->center_x - 2 + x, minimap->center_y - 2 + y,
				0xFFFFFF, g);
			y++;
		}
		x++;
	}
	draw_line(minimap->center_x, minimap->center_y, g->player.angle - FOV / 2,
		g);
	draw_line(minimap->center_x, minimap->center_y, g->player.angle + FOV / 2,
		g);
}

void	draw_wall(t_minimap *minimap, t_game *g)
{
	int	j;
	int	i;
	int	screen_x;
	int	screen_y;

	j = 0;
	while (g->map[j])
	{
		i = 0;
		while (i < (int)ft_strlen(g->map[j]))
		{
			if (g->map[j][i] == '1')
			{
				screen_x = minimap->center_x + (i - minimap->pos_x)
					* minimap->blocksize;
				screen_y = minimap->center_y + (j - minimap->pos_y)
					* minimap->blocksize;
				draw_square(screen_x, screen_y, 0x222222, g);
			}
			i++;
		}
		j++;
	}
}

void	draw_map(t_game *g)
{
	t_minimap	*minimap;

	minimap = &g->minimap;
	minimap->pos_x = (g->player.x / BLOCK_SIZE);
	minimap->pos_y = (g->player.y / BLOCK_SIZE);
	init_minimap2(&g->minimap, &g->player, g);
	draw_background(minimap, g);
	draw_wall(minimap, g);
	draw_player(minimap, g);
}