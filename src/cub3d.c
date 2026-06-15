/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 11:46:19 by marthoma          #+#    #+#             */
/*   Updated: 2026/06/15 18:37:10 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	g;

	if (argc != 2 )
	{
		ft_putstr_fd("Error. Correct input format : ./cub3d <filename>.cub\n",
			2);
		return (1);
	}
	init_game_struct(&g);
	if (parse_input(argv, &g))
		return (free_parse(&g.p), 1);
	printf("x = %f\n", g.player.x);
	printf("y = %f\n", g.player.y);
	printf("angle = %f\n", g.player.angle);
	mlx_hook(g.win, 17, 0, (int (*)())(void *)end, &g);
	mlx_hook(g.win, 2, 1L << 0, (int (*)())(void *)key_press, &g.player);
	mlx_hook(g.win, 3, 1L << 1, (int (*)())(void *)key_release, &g.player);
	mlx_loop_hook(g.mlx, (int (*)())(void *)draw_loop, &g);
	mlx_loop(g.mlx);
	free_parse(&g.p);
	return (0);
}
