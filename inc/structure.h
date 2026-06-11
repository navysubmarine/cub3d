/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemouge <bdemouge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 18:01:54 by bdemouge          #+#    #+#             */
/*   Updated: 2026/06/11 15:41:42 by bdemouge         ###   ########.fr       */
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
	char		*id; // SO, NO, EA, WE parsing
	char		*word; // parsing
	char		**field; // parsing
}				t_tx_info;

typedef struct s_col_info
{
	char		*id; // F, C parsing
	char		*word; // parsing
	int			*field; // parsing
	int			*is_set; // parsing
}				t_col_info;

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

typedef struct s_file
{
	int			nb_of_lines; // parsing
	char		**content; // parsing
	char		*path_no; // parsing
	char		*path_so; // parsing
	char		*path_we; // parsing
	char		*path_ea; // parsing
	int			floor[3]; // parsing
	int			floor_set; // parsing
	int			ceiling[3]; // parsing
	int			ceiling_set; // parsing
}				t_file;

typedef struct s_parse_context
{
	int			i; // parsing
	int			i_map; // parsing
	int			ret_map; // parsing
	int			nb_l; // parsing
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
	// int floor;
	// int ceiling;
	// void *text_no;
	// void *test_so;
	// void *text_ea;
	// void *test_we;
	t_map		map;
	t_file		file;
	t_player	player;
	t_tx_info	textures[4];
	t_col_info	colors[2];
}				t_game;

#endif