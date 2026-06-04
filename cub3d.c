/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 11:46:19 by marthoma          #+#    #+#             */
/*   Updated: 2026/06/04 12:46:08 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_file_content(t_game *g)
{
	int		i;
	int		i_map;
	char	**lines;

	i = 0;
	i_map = 0;
	lines = g->file.content;
	while (i < g->file.nb_of_lines)
	{
		if (blank_line_detector(lines[i]) == TRUE)
		{
			//printf("blank line detector triggered\n");
			i++;
			continue ;
		}
		else if (g->map.is_map_set == FALSE
			&& texture_line_detector(lines[i]) == TRUE)
		{
			//printf("texture line detector triggered\n");
			if (validate_texture_line(lines[i], g))
				return (1);
			i++;
			continue ;
		}
		else if (g->map.is_map_set == FALSE
			&& color_line_detector(lines[i]) == TRUE)
		{
			//printf("color line detector triggered\n");
			if (validate_color_line(lines[i], g))
				return (1);
			i++;
			continue ;
		}
		else if (i < g->file.nb_of_lines && map_line_detector(lines[i]) == TRUE)
		{
			while (i < g->file.nb_of_lines
				&& map_line_detector(lines[i]) == TRUE)
			{
				//printf("map line detector triggered\n");
				if (is_valid_map_line(lines[i]))
					return (1);
				if (g->map.is_map_set == FALSE)
				{
					g->map.is_map_set = TRUE;
					if (init_map(lines, g, i))
						return (1);
				}
				store_map_line(g, lines[i], i_map);
				i_map++;
				i++;
				continue ;
			}
			if (i < g->file.nb_of_lines
				&& blank_line_detector(lines[i]) == TRUE)
			{
				//printf("EOF found\n");
				break ;
			}
		}
		else
		{
			ft_putstr_fd("Error. Unrecognized line\n", 2);
			return (1);
		}
		// 	printf("DEBUG: line %d\n", i);
	}
	
	/*TODO: add validate_all_map_set*/
	if (validate_header_set(&g->file))
		return (1);
	//print_file(g);
	ft_putstr_fd("OK, file is valid. Ready to launch !!\n", 1);
	return (0);
}



// int	is_this_line_only_ones(char *line)
// {
// 	int	i;

// 	i = 0;

// 	while (line[i])
// 	{
// 		if (line[i] != '1' && line[i] != ' ' && line[i] != '\t')
// 			return (1);
// 		while (line[i] == ' ' || line[i] == '\t')
// 			i++;
// 		while (line[i] == '1')
// 			i++;
// 	}
// 	return (0);
// }

void	find_player(t_game *g, char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!map)
		return ;
	g->player.initial_x = -1;
	g->player.initial_y = -1;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] )
			{
				g->player_x = j;
				g->player_y = i;
			}
			j++;
		}
		i++;
	}
}

int	are_walls_enclosed(t_game *g, char **map)
{
	
}

int	where_is_the_player(t_game *g, char **map)
{
	
}

int	is_there_one_player(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'W' || map[i][j] == 'E')
				count ++;
			j++;
		}
		i++;
	}
	if (count != 1)
		return (1);
	return (0);
}

int	handle_player_pos(t_game *g, char **map)
{
	if (is_there_one_player(map))
	{
		printf("Error. There is not exactly one player\n");
		return (1);
	}
	where_is_the_player(g, map);
	return (0);	
}

int	is_map_playable(t_game *g)
{
	int	i;
	char	**copy;

	i = 0;
	copy = map_copy(g->map.map);
	if (!copy)
	{
		ft_putstr_fd("Error. Map couldn't be copied\n", 2);
		return (1);
	}
	/*is there only one player and where is it*/
	if (handle_player_pos(g, copy))
		return (1);
	if (are_walls_enclosed(g, copy))
	{
		printf("Error. Map walls are not closed\n", i);
		return (1);
	}
	while (map[i])
	{
		
		i++;
	}
	
	/*TODO: 1) are the walls enclosed
	2) is there exactly one player
	3) Is the map empty or minimum size
	4) No invalid chars
	*/
}

int	handle_input(int argc, char **argv, t_game *g)
{
	if (argc != 2 || !ft_strchr_cub(argv[1]))
	{
		ft_putstr_fd("Error. Correct input format : ./cub3d <filename>.cub\n",
			2);
		return (1);
	}
	if (handle_file(g, argv[1]))
	{
		ft_putstr_fd("Error. invalid file\n", 2);
		return (1);
	}
	if (handle_file_content(g))
	{
		return (1);
	}
	// if (is_map_playable(g))
	//  	return (1);
	return (0);
}

/*TODO: make the key_handler + init_game + load_sprites functions*/
int	main(int argc, char **argv)
{
	t_game	g;

	ft_memset(&g, 0, sizeof(t_game));
	/*we check if the input file is playable
	+we store what we find in the struct*/
	init_tx_info_struct(&g);
	init_col_info_struct(&g);
	g.map.is_map_set = FALSE;
	if (handle_input(argc, argv, &g))
		return (1);

	//init_game(&g) || load_sprites(&g)
	//	|| render_map(&g)
	//	exit_game(&g, 1);
	//mlx_hook(g.win, 2, 1L << 0, key_handler, &g);
	//mlx_hook(g.win, 17, 0, exit_game, &g);
	//mlx_loop(g.mlx);
}