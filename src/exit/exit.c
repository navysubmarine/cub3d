/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemouge <bdemouge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 15:10:36 by marthoma          #+#    #+#             */
/*   Updated: 2026/06/26 14:42:41 by bdemouge         ###   ########.fr       */
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
	get_next_line(-1);
	if (g->win)
		mlx_destroy_window(g->mlx, g->win);
	if (g->img)
		mlx_destroy_image(g->mlx, g->img);
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
	free_parse(&g->p);
	exit(status);
	return (1);
}
