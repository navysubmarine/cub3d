/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemouge <bdemouge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 16:11:00 by bdemouge          #+#    #+#             */
/*   Updated: 2026/06/24 16:03:11 by bdemouge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool is_in_minimap(int x, int y, t_minimap *minimap)
{
    if (x < minimap->startX)
        return (false);
    if (x > minimap->startX + minimap->width)
        return (false);
    if (y < minimap->startY)
        return (false);
    if (y > minimap->startY + minimap->height)
        return (false);
    return (true);
}

static void draw_square(int x, int y, int color, t_game *g)
{
    int i;
    int j;
    t_minimap *minimap;

    minimap = &g->minimap;
    i = 0;
    while (i < minimap->blockSize - 1)
    {
        j = 0;
        while (j < minimap->blockSize - 1)
        {
            if (is_in_minimap(x + j, y + i, minimap))
                put_pixel(x + j, y + i, color, g);
            j++;
        }
        i++;
    }
}

void init_minimap(t_minimap *minimap, t_player *player, t_game *g)
{
    minimap->blockSize = g->win_height / 4 / MINIMAP_HEIGHT;
    minimap->height = minimap->blockSize * MINIMAP_HEIGHT;
    minimap->width = minimap->blockSize * MINIMAP_WIDTH;
    minimap->startX = 20;
    minimap->startY = g->win_height - minimap->height - 20;
    minimap->radiusX = minimap->width / 2;
    minimap->radiusY = minimap->height / 2;
    minimap->centerX = minimap->startX + minimap->radiusX;
    minimap->centerY = minimap->startY + minimap->radiusY;
    minimap->posX = (player->x / BLOCK_SIZE);
    minimap->posY = (player->y / BLOCK_SIZE);
}

static void draw_background(t_minimap *minimap, t_game *g)
{
    int x;
    int y;

    y = 0;
    while (y < minimap->height)
    {
        x = 0;
        while (x < minimap->width)
        {
            put_pixel(minimap->startX + x, minimap->startY + y, 0x999999, g);
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
    int     line_len;

	cos_angle = cos(angle);
	sin_angle = sin(angle);
    line_len = 0;
	x = 0;
    y = 0;
	while (line_len < 10)
	{
		put_pixel(start_x + x, start_y + y, 0xFF0000, g);
		x += cos_angle;
		y += sin_angle;
        line_len++;
	}
}

static void draw_player(t_minimap *minimap, t_game *g)
{
    int x;
    int y;

    x = 0;
    while (x < 5)
    {
        y = 0;
        while (y < 5)
        {
            put_pixel(minimap->centerX - 2 + x, minimap->centerY - 2 + y, 0xFF0000, g);
            y++;
        }
        x++;
    }
    draw_line(minimap->centerX, minimap->centerY, g->player.angle, g);
}

static void draw_wall(t_minimap *minimap, t_game *g)
{
    int j;
    int i;
    int screen_x;
    int screen_y;

    j = 0;
    while (g->map[j])
    {
        i = 0;
        while (i < (int)ft_strlen(g->map[j]))
        {
            if (g->map[j][i] == '1')
            {
                screen_x = minimap->centerX + (i - minimap->posX) * minimap->blockSize;
                screen_y = minimap->centerY + (j - minimap->posY) * minimap->blockSize;
                draw_square(screen_x, screen_y, 0x222222, g);
            }
            i++;
        }
        j++;
    }
}

void draw_map(t_game *g)
{
    t_minimap *minimap;
    
    minimap = &g->minimap;
    minimap->posX = (g->player.x / BLOCK_SIZE);
    minimap->posY = (g->player.y / BLOCK_SIZE);
    init_minimap(&g->minimap, &g->player, g);
    draw_background(minimap, g);
    draw_wall(minimap, g);
    draw_player(minimap, g);
}