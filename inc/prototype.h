/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototype.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 11:46:38 by marthoma          #+#    #+#             */
/*   Updated: 2026/06/11 16:01:24 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPE_H
# define PROTOTYPE_H

// # ifndef BUFFER_SIZE
// #  define BUFFER_SIZE 1000
// # endif

// # ifndef FD_OPEN_MAX
// #  define FD_OPEN_MAX 1024
// # endif

// # include "../libft/libft.h"
// //# include "minilibx/mlx.h"
// # include <fcntl.h>
// # include <limits.h>
// # include <stdbool.h>
// # include <stdio.h>
// # include <stdlib.h>
// # include <unistd.h>

// # define TRUE 1
// # define FALSE 0

// typedef struct s_tx_info
// {
// 	char		*id;
// 	char		*word;
// 	char		**field;
// }				t_tx_info;

// typedef struct s_col_info
// {
// 	char		*id;
// 	char		*word;
// 	int			*field;
// 	int			*is_set;
// }				t_col_info;

// typedef struct s_map
// {
// 	char		**map;
// 	char		**copy;
// 	char		**padded_copy;
// 	int			map_h;
// 	bool		is_map_set;
// 	bool		valid;
// }				t_map;

// typedef struct s_img
// {
// 	int			i;
// }				t_img;

// typedef struct s_player
// {
// 	int			initial_x;
// 	int			initial_y;
// 	int			x;
// 	int			y;
// }				t_player;

// typedef struct s_file
// {
// 	int			nb_of_lines;
// 	char		**content;
// 	char		*path_no;
// 	char		*path_so;
// 	char		*path_we;
// 	char		*path_ea;
// 	int			floor[3];
// 	int			floor_set;
// 	int			ceiling[3];
// 	int			ceiling_set;
// }				t_file;

// typedef struct s_game
// {
// 	void		*mlx;
// 	void		*win;
// 	t_img		img;
// 	t_map		map;
// 	t_file		file;
// 	t_player	player;
// 	t_tx_info	textures[4];
// 	t_col_info	colors[2];
// }				t_game;

/*INIT STRUCTS*/
void			init_game_struct(t_game *g);
void			init_context_struct(t_parse_context *data, t_parse *p);
/****PARSING****/
int				parse_input(int argc, char **argv, t_game *g);
int				ft_strchr_cub(const char *s);
int				handle_file(t_parse *p, char *filename);
int				handle_file_content(t_parse *p);
int				handle_line(t_parse_context *c, t_parse *p);

char			*find_content(char *line, char *id);
int				assign_field_once(char **struct_path, char *line);
int				count_lines(int fd);
char			**store_content(char *file, int nb_of_lines);
int				validate_header_set(t_file *file);
int				blank_line_detector(char *line);
/*MAP*/
int				is_valid_map_line(char *line);
int				map_detector(char *line);
void			store_map_line(t_parse *p, char *line, int i);
int				calculate_map_len(char **lines, int i, t_parse *p);
int				init_map(char **lines, t_parse *p, int i);
char			**map_padded_copy(char **map, t_parse *p);
char			**map_copy(char **map);
int				handle_player_pos(t_parse *p, char **map);
void			are_walls_enclosed(t_map *map, int x, int y, int nb_lines);
int				is_map_playable(t_parse *p);
int				are_there_still_spaces(t_map *map);
int				handle_map(int *i, int *i_map, t_parse *p, char **lines);
int				find_longest_line_len(char **map);
void			find_player(t_parse *p, char **map);
/*TEXTURE*/
int				validate_texture_line(char	*line, t_parse *p);
int				tx_detector(char *line);
int				test_tx_path(char *tx_type, char *path);
/*COLORS*/
int				validate_color_line(char *line, t_parse *p);
int				test_rgb_format(char *content);
int				test_rgb_color(char *id, char *content);
int				store_rgb(int *values, char *content);
int				col_detector(char *line);
/*GET NEXT LINE*/
char			*get_next_line(int fd);
char			*call_and_check(int fd, char *buffer, char **stash);
int				read_and_fill_stash(int fd, char *buffer, char **stash);
char			*update_stash(char **stash);
char			*set_line(char *stash);
char			*clear_stash(char *stash_array[FD_OPEN_MAX]);
/*EXIT*/
int				exit_game(t_game *g, int error);
void			free_content(char **content);
//void			free_all(t_game *g);
/*PRINT*/
void			print_file(t_game *g);
void			print_map(char **map, char *name);
/*UTILS*/
char			*ft_strdup_padded(const char *s, int padded_line_len);

/*PROTOTYPES BASTIEN*/
// void			safe_free(void *ptr);
// void			exit_prog(t_data *game, int retval);
// char			**get_map(void);
// int				key_press(int keycode, void *ply);
// int				key_release(int keycode, void *ply);
// void			move_player(t_data *game);
// void			init_player(float x, float y, float angle, t_player *player);
// bool			touch(float x, float y, t_data *game);
// void			put_pixel(int x, int y, int color, t_data *game);
// void			raycasting(t_data *game);

#endif