/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototype.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemouge <bdemouge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 18:01:47 by bdemouge          #+#    #+#             */
/*   Updated: 2026/06/09 18:01:48 by bdemouge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPE_H
# define PROTOTYPE_H

/*INIT STRUCTS*/
void			init_structs(t_game *g);
/****PARSING INPUT FILE****/
int				parse_input(int argc, char **argv, t_game *g);
int				handle_file_content(t_game *g);
int				ft_strchr_cub(const char *s);
int				handle_file(t_game *g, char *filename);
char			*find_content(char *line, char *id);
int				assign_field_once(char **struct_path, char *line);
int				count_lines(int fd);
char			**store_content(char *file, int nb_of_lines);
int				blank_line_detector(char	*line);
/*PARSING MAP*/
int				is_valid_map_line(char	*line);
int				map_line_detector(char *line);
void			store_map_line(t_game *g, char *line, int i);
int				calculate_map_len(char **lines, int i, t_game *g);
int				init_map(char **lines, t_game *g, int i);
char			**map_padded_copy(char **map, t_game *g);
char			**map_copy(char **map);
int				handle_player_pos(t_game *g, char **map);
void			are_walls_enclosed(t_map *map, int x, int y, int nb_lines);
int				is_map_playable(t_game *g);
int				are_there_still_spaces(t_map *map);
int				handle_map(int *i, int *i_map, t_game *g, char **lines);
int				find_longest_line_len(char **map);
/*PARSING HEADER*/
int				validate_header_set(t_file *file);
/*PARSING TEXTURE*/
int				validate_texture_line(char	*line, t_game *g);
int				texture_line_detector(char *line);
int				test_tx_path(char *tx_type, char *path);
/*PARSING COLORS*/
int				validate_color_line(char *line, t_game *g);
int				test_rgb_format(char *content);
int				test_rgb_color(char	*id, char *content);
int				store_rgb(int *values, char *content);
int				color_line_detector(char *line);
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
void			free_all(t_game *g);
/*PRINT*/
void			print_file(t_game *g);
/*UTILS*/
char			*ft_strdup_padded(const char *s, int padded_line_len);
void			print_map(char **map, char *name);

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