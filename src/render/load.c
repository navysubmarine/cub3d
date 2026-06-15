/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 15:03:06 by marthoma          #+#    #+#             */
/*   Updated: 2026/06/15 15:09:20 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_wall_sprites(t_game *g)
{
	int	w;
	int	h;

	w = BLOCK_SIZE;
	h = BLOCK_SIZE;
	g->img.n_wall = mlx_xpm_file_to_image(g->mlx, g->path_no_tx, &w,
			&h);
	if (!g->img.n_wall)
	{
		ft_putstr_fd("Error: Northern wall sprite could not be loaded\n", 2);
		exit_game(g, 1);
	}
	g->img.s_wall = mlx_xpm_file_to_image(g->mlx, g->path_so_tx, &w,
			&h);
	if (g->img.s_wall)
	{
		ft_putstr_fd("Error: Southern wall sprite could not be loaded\n", 2);
		exit_game(g, 1);
	}
	g->img.e_wall = mlx_xpm_file_to_image(g->mlx, g->path_ea_tx, &w,
			&h);
	if (g->img.e_wall)
	{
		ft_putstr_fd("Error: Eastern wall sprite could not be loaded\n", 2);
		exit_game(g, 1);
	}
	g->img.w_wall = mlx_xpm_file_to_image(g->mlx, g->path_we_tx, &w,
			&h);
	if (g->img.w_wall)
	{
		ft_putstr_fd("Error: Western wall sprite could not be loaded\n", 2);
		exit_game(g, 1);
	}
}