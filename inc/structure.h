/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 18:01:54 by bdemouge          #+#    #+#             */
/*   Updated: 2026/06/23 14:47:06 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

/*===== ENUM =====*/
typedef enum			e_textureid
{
	NO = 0,
	SO = 1,
	WE = 2,
	EA = 3,
	ERROR = 4
}			t_textureid;

typedef struct s_tx_info
{
	char *id; // SO, NO, EA, WE a supprimer
	char		*word;
	char		*path;
	int			is_set;
}				t_tx_info;

typedef struct s_col_info
{
	char		*id;
	char		*word;
	int			rgb[3];
	int			is_set;
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
	float		x;
	float		y;
	float		angle;

	bool		forward;
	bool		backward;
	bool		right;
	bool		left;
	bool		right_rotate;
	bool		left_rotate;
	bool		exit;
}				t_player;

typedef struct s_parse_context
{
	int			i;
	int			i_map;
	int			ret_map;
	int			nb_l;
}				t_parse_context;

typedef struct s_parse
{
	int			nb_of_lines;
	char		**content;
	t_map		map;
	t_player	player;
	t_tx_info	textures[4];
	t_col_info	colors[2];
}				t_parse;

typedef struct s_tx_data
{
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}				t_tx_data;

typedef struct s_img
{
	void		*n_wall;
	void		*s_wall;
	void		*w_wall;
	void		*e_wall;
	t_tx_data	n_data;
	t_tx_data	s_data;
	t_tx_data	w_data;
	t_tx_data	e_data;
}				t_img;

typedef struct s_dda_context
{
	float	cos_a;
	float	sin_a;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	float	hit_x;
	float	hit_y;
	float	side_dist_x;
	float	side_dist_y;
	float	delta_dist_x;
	float	delta_dist_y;
	float	dist;
	int		side;
	float	wall_x;
}				t_dda_context;

typedef struct s_render_context
{
	float		wall_height;
	int			bottom_y;
	int			top_y;
	int			tex_x;
	int			tex_y;
	float		step;
	float		tex_pos;
	int			screen_y;// that pixel on the screen
}				t_render_context;

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

	int			floor;
	int			ceiling;
	char		*path_no_tx;
	char		*path_so_tx;
	char		*path_we_tx;
	char		*path_ea_tx;
	char		**map;
	t_parse		p;
	t_player	player;
	t_img		i;
}				t_game;

#endif