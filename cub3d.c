/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 11:46:19 by marthoma          #+#    #+#             */
/*   Updated: 2026/05/28 11:43:54 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



int	validate_texture_line(char	*line, t_game *g)
{
	char	*content;
	int		i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (ft_strncmp(line + i, "NO ", 3) == 0 && line[3 + i] != '\0')
	{
		content = find_content(line + i, "NO");
		if (test_tx_path("North", content))
			return (1);
		else
		{
			if (assign_field_once(&g->file.path_no, content))
				return (1);
		}
	}
	else if (ft_strncmp(line + i, "SO ", 3) == 0 && line[3 + i] != '\0')
	{
		content = find_content(line + i, "SO");
		if (test_tx_path("South", content))
			return (1);
		else
		{
			if (assign_field_once(&g->file.path_so, content))
				return (1);
		}
	}
	else if (ft_strncmp(line + i, "WE ", 3) == 0 && line[3 + i] != '\0')
	{
		content = find_content(line + i, "WE");
		if (test_tx_path("West", content))
			return (1);
		else
		{
			if (assign_field_once(&g->file.path_we, content))
				return (1);
		}
	}
	else if (ft_strncmp(line + i, "EA ", 3) == 0 && line[3 + i] != '\0')
	{
		content = find_content(line + i, "EA");
		if (test_tx_path("East", content))
			return (1);
		else
		{
			if (assign_field_once(&g->file.path_ea, content))
				return (1);
		}
	}
	return (0);
}

int	validate_color_line(char	*line, t_game *g)
{
	char	*content;
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (ft_strncmp(line + i, "F ", 2) == 0 && (line[2] + i) != '\0')
	{
		content = find_content(line + i, "F");

		if (test_rgb_color("Floor", content))
			return (1);
		else
		{
			if (store_rgb(g->file.floor, content))
				return (1);
			else
				g->file.floor_set = 1;
		}
	}
	else if (ft_strncmp(line + i, "C ", 2) == 0 && line[2] != '\0')
	{
		content = find_content(line + i, "C");
		if (test_rgb_color("Ceiling", content))
			return (1);
		else
		{
			if (store_rgb(g->file.ceiling, content))
				return (1);
			else
				g->file.ceiling_set = 1;
		}
	}
	else
		return (1);
	return (0);
}

int validate_all_header_set(t_file *file)
{
	if (!file->path_no)
	{
		ft_putstr_fd("Error. Missing north texture\n", 2);
		return (1);
	}
	if (!file->path_so)
	{
		ft_putstr_fd("Error. Missing south texture\n", 2);
		return (1);
	}
	if (!file->path_we)
	{
		ft_putstr_fd("Error. Missing west texture\n", 2);
		return (1);
	}
	if (!file->path_ea)
	{
		ft_putstr_fd("Error. Missing east texture\n", 2);
		return (1);
	}
	if (!file->floor_set)
	{
		ft_putstr_fd("Error. Missing floor color\n", 2);
		return (1);
	}
	if (!file->ceiling_set)
	{
		ft_putstr_fd("Error. Missing ceiling color\n", 2);
		return (1);
	}
	return (0);
}

int	texture_line_detector(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	/*0=yes it's a texture line, 1=no*/
	if (ft_strncmp(line + i, "NO ", 3) == TRUE)
		return (TRUE);
	else if (ft_strncmp(line + i, "SO ", 3) == TRUE)
		return (TRUE);
	else if (ft_strncmp(line + i, "WE ", 3) == TRUE)
		return (TRUE);
	else if (ft_strncmp(line + i, "EA ", 3) == TRUE)
		return (TRUE);
	else
		return (FALSE);
}

int	color_line_detector(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	/*0=yes it's a color line, 1=no*/
	if (ft_strncmp(line + i, "F ", 2) == 0)
		return (0);
	else if (ft_strncmp(line + i, "C ", 2) == 0)
		return (0);
	else
		return (1);
}

int	blank_line_detector(char	*line)
{
	int	i;

	i = 0;
	if (line[0] == '\0' || line[0] == '\n')
		return (TRUE);
	while (line[i] == ' ' || line[i] == '\t')
	{
		i++;
	}
	if (line[i] == '\0' || line[i] == '\n')
		return (TRUE);
	else
		return (FALSE);
}
/*
int	store_map_line(t_game *g, char *line)
{

}
*/

int	calculate_map_len(int i, t_game *g)
{
	g->map.map_h = g->file.nb_of_lines - i;
	if (g->map.map_h <= 0)
	{
		ft_putstr_fd("Error. Map doesn't exist\n", 2);
		return (1);
	}
	return (0);
}

int	init_map(t_game *g, int i)
{
	if (calculate_map_len(i, g))
		return (1);
	g->map.map = ft_calloc(g->map.map_h + 1, sizeof (char *));
	if (!g->map.map)
	{
		ft_putstr_fd("Error. Malloc map failed\n", 2);
		return (1);
	}
	return (0);
}

int	handle_file_content(t_game *g)
{
	int		i;
	char	**lines;

	i = 0;
	lines = g->file.content;
	while (i < g->file.nb_of_lines)
	{
		if (blank_line_detector(lines[i]) == TRUE)
		{
			i++;
			continue ;
		}
		else if (g->map.is_map_set == FALSE && texture_line_detector(lines[i]) == TRUE)
		{
			if (validate_texture_line(lines[i], g))
				return (1);
		}
		else if (g->map.is_map_set== FALSE && color_line_detector(lines[i]) == TRUE)
		{
			if (validate_color_line(lines[i], g))
				return (1);
		}
		else if (map_line_detector(lines[i]) == TRUE)
		{
			/*TODO: parse the map and validate it*/
			/*Store the map and check it after everyline has been collected*/
			if (is_valid_map_line(lines[i]))
			 	return (1);
			// /*TODO: this function, after having initialized the map with the right number of lines*/
			if (g->map.is_map_set == FALSE)
			{
				g->map.is_map_set = TRUE;
				if (init_map(g, i))
					return (1);
				printf("map_set ? : %i\n", g->map.is_map_set);
			}
			// if (store_map_line(g, lines[i]))
			// 	return (1);
			break ;
		}
		else
		{
			printf("DEBUG: line %d\n", i);
			ft_putstr_fd("Error. Unrecognized line\n", 2);
			return (1);
		}
		i++;
	}
	
	/*TODO: add validate_all_map_set*/
	if (validate_all_header_set(&g->file))
		return (1);
	//print_file(&g->file);
	//ft_putstr_fd("OK, file is valid. Ready to launch !!\n", 1);
	return (0);
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
	/*TODO: make this function*/
	// if (is_map_playable(g))
	// 	return (1);
	return (0);
}

/*TODO: make the key_handler + init_game + load_sprites functions*/
int	main(int argc, char **argv)
{
	t_game	g;

	ft_memset(&g, 0, sizeof(t_game));
	/*we check if the input file is playable
	+we store what we find in the struct*/
	if (handle_input(argc, argv, &g))
		return (1);

	//init_game(&g) || load_sprites(&g)
	//	|| render_map(&g)
	//	exit_game(&g, 1);
	//mlx_hook(g.win, 2, 1L << 0, key_handler, &g);
	//mlx_hook(g.win, 17, 0, exit_game, &g);
	//mlx_loop(g.mlx);
}