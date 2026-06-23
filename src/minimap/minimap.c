/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemouge <bdemouge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 16:11:00 by bdemouge          #+#    #+#             */
/*   Updated: 2026/06/23 18:22:05 by bdemouge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static bool is_in_minimap(t_game *game)

// static void draw_block(double x, double y, t_game *g)
// {
//     int i;
//     int j;
//     t_minimap *minimap;

//     minimap = &g->minimap;
//     i = 0;
//     while (i < minimap->blockSize - 1)
//     {
//         j = 0;
//         while (j < minimap->blockSize - 1)
//         {
//             put_pixel(x + j, y + i, 0xAAAAAA, g);
//             j++;
//         }
//         i++;
//     }
// }

//static bool is_wall(int x, int y, t_game *g)

void draw_map(t_game *g)
{
    t_minimap *minimap;
    int x;
    int y;
    
    minimap = &g->minimap;
    minimap->blockSize = g->win_height / 4 / MINIMAP_WIDTH;
    minimap->height = minimap->blockSize * MINIMAP_HEIGHT;
    minimap->width = minimap->blockSize * MINIMAP_WIDTH;
    minimap->startX = 10;
    minimap->startY = g->win_height - minimap->height - 10;
    minimap->centerX = minimap->startX + minimap->width / 2;
    minimap->centerY = minimap->startY + minimap->height / 2;
    y = 0;
    while (y < minimap->height)
    {
        x = 0;
        while (x < minimap->width)
        {
            put_pixel(minimap->startX + x, minimap->startY + y, 0x111111, g);
            x++;   
        }
        y++;
    }
    put_pixel(minimap->centerX, minimap->centerY, 0xFF, g);
}