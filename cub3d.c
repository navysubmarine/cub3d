/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 11:46:19 by marthoma          #+#    #+#             */
/*   Updated: 2026/06/10 18:03:47 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	g;

	init_structs(&g);
	if (parse_input(argc, argv, &g))
		return (1);
}
	// init_game(&g) || load_sprites(&g)
	// 	|| render_map(&g)
	// 	exit_game(&g, 1);
	// mlx_hook(g.win, 2, 1L << 0, key_handler, &g);
	// mlx_hook(g.win, 17, 0, exit_game, &g);
	// mlx_loop(g.mlx);