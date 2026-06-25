/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 11:46:19 by marthoma          #+#    #+#             */
/*   Updated: 2026/06/25 16:24:07 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	draw_loop(void *param)
{
	t_game	*g;

	g = (t_game *)param;
	fill_background_colors(g);
	move_player(g);
	raycasting(g);
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
	mlx_hook(g.win, 17, 0, (int (*)())(void *)end, &g);
	mlx_hook(g.win, 2, 1L << 0, (int (*)())(void *)key_press, &g.player);
	mlx_hook(g.win, 3, 1L << 1, (int (*)())(void *)key_release, &g.player);
	mlx_loop_hook(g.mlx, (int (*)())(void *)draw_loop, &g);
	mlx_loop(g.mlx);
	free_parse(&g.p);
	return (0);
}
