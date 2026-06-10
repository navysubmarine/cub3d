/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 18:01:54 by bdemouge          #+#    #+#             */
/*   Updated: 2026/06/10 19:05:27 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

/*===== ENUM =====*/
enum e_textureid
{
	NO = 0,
	SO = 1,
	WE = 2,
	EA = 3
};


typedef struct s_tx_info
{
	char		*id; // SO, NO, EA, WE a supprimer
	char		*word; 
	char		**field;
}				t_tx_info;

typedef struct s_col_info
{
	char		*id; // F, C
	char		*word;
	int			*field;
	int			*is_set;
}				t_col_info;

typedef struct s_map
{
	char		**map;
	char		**copy;
	char		**padded_copy;
	int			map_h;
	bool		is_map_set;
	bool		valid;
}				t_map;

typedef struct s_player
{
	int			initial_x;
	int			initial_y;
	int			x;
	int			y;
}				t_player;

typedef struct s_file
{
	int			nb_of_lines;
	char		**content;
	char		*path_no; 
	char		*path_so;
	char		*path_we;
	char		*path_ea;
	int			floor[3];
	int			floor_set;
	int			ceiling[3];
	int			ceiling_set;
}				t_file;

typedef struct s_parse_context
{
	int			i;
	int			i_map;
	int			ret_map;
	int			nb_l;
}				t_parse_context;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bpp;
	int			line_length;
	int			endian;

	int			win_height;
	int			win_width;
	t_map		map;
	t_file		file;
	t_player	player;
	t_tx_info	textures[4];
	t_col_info	colors[2];
}				t_game;

// STRUCTURES BASTIEN

// typedef struct s_player
// {
// 	float		x;
// 	float		y;
// 	float		angle;

// 	bool		forward;
// 	bool		backward;
// 	bool		right;
// 	bool		left;
// 	bool		right_rotate;
// 	bool		left_rotate;
// }				t_player;

// typedef struct s_data
// {
// 	void		*mlx;
// 	void		*win;
// 	void		*img;
// 	char		*addr;
// 	int			bpp;
// 	int			line_length;
// 	int			endian;

// 	int			height;
// 	int			width;
// 	t_player	player;
// 	char		**map;
// }				t_data;

#endif