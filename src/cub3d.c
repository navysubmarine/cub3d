/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemouge <bdemouge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 11:46:19 by marthoma          #+#    #+#             */
/*   Updated: 2026/06/25 17:41:36 by bdemouge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	draw_loop(void *param)
{
	t_game	*g;

	g = (t_game *)param;
	fill_background_colors(g);
	if (BONUS)
		move_player_collision(g);
	else
		move_player(g);
	raycasting(g);
	if (BONUS)
		draw_map(g);
	mlx_put_image_to_window(g->mlx, g->win, g->img, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	g;

	init_game_struct(&g);
	if (parse_input(argc, argv, &g))
		return (free_parse(&g.p), 1);
	init_mlx_struct(&g);
	init_minimap(&g.minimap, &g);
	mlx_hook(g.win, 17, 0, (int (*)())(void *)end, &g);
	mlx_hook(g.win, 2, 1L << 0, (int (*)())(void *)key_press, &g.player);
	mlx_hook(g.win, 3, 1L << 1, (int (*)())(void *)key_release, &g.player);
	mlx_loop_hook(g.mlx, (int (*)())(void *)draw_loop, &g);
	mlx_loop(g.mlx);
	free_parse(&g.p);
	return (0);
}
