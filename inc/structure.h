/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 18:01:54 by bdemouge          #+#    #+#             */
/*   Updated: 2026/06/12 15:17:17 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

/*===== ENUM =====*/
enum				e_textureid
{
	NO = 0,
	SO = 1,
	WE = 2,
	EA = 3
};

typedef struct s_tx_info
{
	char 			*id; // SO, NO, EA, WE a supprimer
	char			*word;
	char			*path;
	int				is_set;
}					t_tx_info;

typedef struct s_col_info
{
	char			*id; // F, C
	char			*word;
	int				rgb[3];
	int				is_set;
}					t_col_info;

typedef struct s_map
{
	char		**map;
	char		**copy; // parsing
	char		**padded_copy; // parsing
	int			map_h; // parsing
	bool		is_map_set; // parsing
	bool		valid; // parsing
}				t_map;

typedef struct s_player
{
	int			initial_x;
	int			initial_y;
	float 		x;
	float 		y;
	float 		angle;
	
	bool		forward;
 	bool		backward;
 	bool		right;
 	bool		left;
 	bool		right_rotate;
 	bool		left_rotate;
	bool 		exit;
}				t_player;

typedef struct s_parse_context
{
	int				i;
	int				i_map;
	int				ret_map;
	int				nb_l;
}					t_parse_context;

typedef struct s_parse
{
	int				nb_of_lines;
	char			**content;
	t_map			map;
	t_player		player;
	t_tx_info		textures[4];
	t_col_info		colors[2];
}					t_parse;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				bpp;
	int				line_length;
	int				endian;
	int				win_height;
	int				win_width;

	int				floor;
	int				ceiling;
	char			*path_no_tx;
	char			*path_so_tx;
	char			*path_we_tx;
	char			*path_ea_tx;
	char			**map;
	t_parse			p;
}					t_game;

#endif