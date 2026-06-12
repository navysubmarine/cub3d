/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 11:46:19 by marthoma          #+#    #+#             */
/*   Updated: 2026/06/12 15:18:21 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	g;

	init_game_struct(&g);
	if (parse_input(argc, argv, &g))
		return (free_parse(&g.p), 1);
	mlx_hook(g.win, 17, 0, (int (*)())(void *)end, &g);
	mlx_hook(g.win, 2, 1L << 0, (int (*)())(void *)key_press, &g.player);
	mlx_hook(g.win, 3, 1L << 1, (int (*)())(void *)key_release, &g.player);
	mlx_loop_hook(g.mlx, (int (*)())(void *)draw_loop, &g);
	mlx_loop(g.mlx);
	free_parse(&g.p);
	return (0);
}
// init_game(&g) || load_sprites(&g)
// 	|| render_map(&g)
// 	exit_game(&g, 1);
// mlx_hook(g.win, 2, 1L << 0, key_handler, &g);
// mlx_hook(g.win, 17, 0, exit_game, &g);
// mlx_loop(g.mlx);