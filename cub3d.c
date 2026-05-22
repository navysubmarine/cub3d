/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 11:46:19 by marthoma          #+#    #+#             */
/*   Updated: 2026/05/22 16:27:15 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_game_struct(t_game *g)
{
	ft_memset(&g, 0, sizeof(t_game));
}

/*TODO: make the init map (creating an array of strings, easier to check)
and check_map function(s)*/
int	check_input(int argc, char **argv, t_game *g)
{
	if (argc != 2 || !ft_strchr_cub(argv[1]))
	{
		ft_putstr_fd("Error. Correct input format : ./cub3d <filename>.cub\n",
			2);
		return (1);
	}
	init_map1;
	check_map1;
	return (0);
}

/*TODO: make the key_handler + init_game + load_sprites functions*/
int	main(int argc, char **argv)
{
	t_game	g;

	if (init_game_struct(&g) || check_input(argc, argv, &g) || init_game(&g)
		|| load_sprites(&g) || render_map(&g))
		exit_game(&g, 1);
	mlx_hook(g.win, 2, 1L << 0, key_handler, &g);
	mlx_hook(g.win, 17, 0, exit_game, &g);
	mlx_loop(g.mlx);
}