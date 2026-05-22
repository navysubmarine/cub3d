/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 11:46:38 by marthoma          #+#    #+#             */
/*   Updated: 2026/05/22 15:19:46 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*TODO: structure globale sur l'etat de jeu + autre structure pour le player*/

#ifndef CUB3D_H
# define CUB3D_H

typedef struct s_img
{
}				t_img;

typedef struct s_player
{
}				t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	int			map_w;
	int			map_h;
	int			player_x;
	int			player_y;
	int			total_collect;
	int			collect_left;
	int			moves;
	char		**test_map;
	t_img		img;
}				t_game;

/*CHECK MAP*/

int	ft_strchr_cub(const char *s);

#endif