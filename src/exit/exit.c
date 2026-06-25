/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemouge <bdemouge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 15:10:36 by marthoma          #+#    #+#             */
/*   Updated: 2026/06/25 17:33:54 by bdemouge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	end(t_game *g)
{
	exit_game(g, 0);
	return (1);
}

int	exit_game(t_game *g, int status)
{
	if (g->win)
		mlx_destroy_window(g->mlx, g->win);
	if (g->i.n_wall)
		mlx_destroy_image(g->mlx, g->i.n_wall);
	if (g->i.s_wall)
		mlx_destroy_image(g->mlx, g->i.s_wall);
	if (g->i.e_wall)
		mlx_destroy_image(g->mlx, g->i.e_wall);
	if (g->i.w_wall)
		mlx_destroy_image(g->mlx, g->i.w_wall);
	if (g->mlx)
	{
		mlx_destroy_display(g->mlx);
		safe_free(g->mlx);
	}
	exit(status);
	return (1);
}
