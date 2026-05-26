/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 11:46:19 by marthoma          #+#    #+#             */
/*   Updated: 2026/05/26 12:01:30 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static unsigned int	count_lines(int fd)
{
	char	*line;
	int		count;

	count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			break ;
		}
		count++;
		free(line);
	}
	close(fd);
	return (count);
}

char	**store_content(char *file, int nb_of_lines)
{
	char	**content;
	int		fd;
	int		i;
	char	*eol;

	i = 0;
	content = malloc(sizeof(char *) * (nb_of_lines + 1));
	if (!content)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (free(content), NULL);
	while (i < nb_of_lines)
	{
		content[i] = get_next_line(fd);
		if (!content[i])
			return (free_content(content), close(fd), NULL);
		eol = ft_strchr(content[i], '\n');
		if (eol)
			*eol = '\0';
		i++;
	}
	return (content[i] = NULL, close(fd), content);
}

static int	check_file(t_game *g, char *filename)
{
	int	fd;
	/*we check if the file exists*/
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (1);
	/*we store the nb of lines inside the g struct*/
	g->file.nb_of_lines = count_lines(fd);
	/*we store the content of the file inside an array of strings*/
	g->file.content = store_content(filename, g->file.nb_of_lines);
	return (0);
}


/*TODO: make check map function*/\
// int	check_map(t_game *g, char *filename)
// {

// }
/*
int	check_textures(t_game *g)
{
	char	*f_content;

	f_content = g->file.content;
	g->file.path_no = ft_strnstr(f_content, "NO ./", 6) + 5;
	if (!g->file.path_no)
	{
		ft_putstr_fd("Error. Incorrect North texture\n", 33);
		return (1);
	}
	
}
*/
/*
int	parse_config(char **lines, int count, t_map *map)
{
	int	i = 0;

	// Pass 1: header entries (until we hit a map line)
	while (i < count && !is_map_line(lines[i])) {
		if (*lines[i] != '\0' && parse_header_line(lines[i], map) != 0)
			return -1;
		i++;
	}

	// Pass 2: map (everything from here to EOF)
	if (i >= count)
		return (error("no map found"), -1);
	return parse_map_section(&lines[i], count - i, map);
}
*/

int	is_valid_map_line(char	*line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '0' && line[i] != '1'
			&& line[i] != 'N' && line[i] != 'S'
			&& line[i] != 'E' && line[i] != 'W'
			&& line[i] != ' ' && line[i] != 9)
		{
			ft_putstr_fd("Error. Invalid character in map line\n", 2);
			return (1);
		}
		i++;
	}
	return (0);
}

int	test_tx_path(char *tx_type, char *path)
{
	
}

int	is_valid_texture_line(char	*line, t_game *g)
{
	int	i;

	i = 0;
	if (!line || line[0] == '\0' || line[0] == '\n' || line[0]== '\t')
		return (1);

	if (ft_strncmp(line, "NO ./", 5) == 0 && line[5] != '\0')
	{
		if (test_tx_path("north", line[5]))
		{
			return (1);
		}
	}
	else if (ft_strncmp(line, "SO ./", 5) == 0 && line[5] != '\0')
	{
		
	}
	else if (ft_strncmp(line, "WE ./", 5) == 0 && line[5] != '\0')
	{
		
	}
	else if (ft_strncmp(line, "EA ./", 5) == 0 && line[5] != '\0')
	{
		
	}
	else if (ft_strncmp(line, "F ", 2) == 0 && line[2] != '\0')
	{
		
	}
	else if (ft_strncmp(line, "C ", 2) == 0 && line[2] != '\0')
	{
		
	}
	else
		return (1);
}

int	is_valid_color_line(char	*line)
{
	// int	i;

	// i = 0;
	// while (line[i] != '\0')
	// {
	// 	if (line[i] != '0' && line[i] != '1'
	// 		&& line[i] != 'N' && line[i] != 'S'
	// 		&& line[i] != 'E' && line[i] != 'W'
	// 		&& line[i] != ' ' && line[i] != 9)
	// 	{
	// 		ft_putstr_fd("Error. Invalid character in map line\n", 2);
	// 		return (1);
	// 	}
	// 	i++;
	// }
	// return (0);
}

int	set_var(char **struct_path, char *line)
{
	if (*struct_path)
	{
		ft_putstr_fd("Error. Duplicate identifyer\n", 2);
		return (1);
	}
	*struct_path = ft_strdup(line);
	return (*struct_path == NULL);
}

static char	*match_content(char *line, char *id)
{
	int	len;
	int i;

	len = ft_strlen(id);
	if (ft_strncmp(line, id, len) != 0)
		return (NULL);
	if (line[len] != ' ' && line[len] != '\t')
		return (NULL);
	i = len;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	return (&line[i]);
}

int	line_type(char *line, t_file *file)
{
	char	*content;

	content = match_content(line, "NO");
	if (content)
	{
		if (set_var(&file->path_no, content))
			return (1);
		return (0);
	}
	content = match_content(line, "SO");
	if (content)
	{
		if (set_var(&file->path_so, content))
			return (1);
		return (0);
	}
	content = match_content(line, "WE");
	if (content)
	{
		if (set_var(&file->path_we, content))
			return (1);
		return (0);
	}
	content = match_content(line, "EA");
	if (content)
	{
		if (set_var(&file->path_ea, content))
			return (1);
		return (0);
	}
	/*TODO:how to transform the string into a three elements array of int*/
	/*
	content = match_content(line, "F");
	if (content)
	{
		if (set_var(file->floor, content))
			return (1);
		return (0);
	}
	content = match_content(line, "C");
	if (content)
	{
		if (set_var(file->ceiling, content))
			return (1);
		return (0);
	}
	*/
	return (1);
}

int	parse_header_line(char *line, t_file *file)
{
	char	*new_line;
	int		ret;

	new_line = ft_strtrim(line, " \t");
	if (!new_line)
		return (1);
	ret = line_type(new_line, file);
	if (ret)
	{
		ft_putstr_fd("Error. File line not recognized\n", 2);
		free(new_line);
		return (1);
	}
	free(new_line);
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
	if (!file->floor)
	{
		ft_putstr_fd("Error. Missing floor color\n", 2);
		return (1);
	}
	if (!file->ceiling)
	{
		ft_putstr_fd("Error. Missing ceiling color\n", 2);
		return (1);
	}
	return (0);
}

int	check_content(t_game *g)
{
	int		i;
	char	**lines;

	i = 0;
	lines = g->file.content;
	/*TODO: remake the logic to identify if it's map or header
	line - or empty line*/
	while (i < g->file.nb_of_lines)
	{
		if (!is_valid_texture_line(lines[i], g))
		{
			
		}
		else if (!is_valid_color_line(lines[i], g))
		{
			
		}
		else if (!is_valid_map_line(lines[i], g))
		{
			
		}
		else
		{
			ft_putstr_fd("Error. Line %d is invalid\n", i);
			return (1);
		}
		// if (parse_header_line(lines[i], &g->file))
		// 	return (1);
		i++;
	}
	if (validate_all_header_set(&g->file) && validate_all_map(&g->file))
		return (1);
	ft_putstr_fd("OK, file is valid. Ready to launch !!\n", 1);
	return (0);
}

int	check_input(int argc, char **argv, t_game *g)
{
	if (argc != 2 || !ft_strchr_cub(argv[1]))
	{
		ft_putstr_fd("Error. Correct input format : ./cub3d <filename>.cub\n",
			2);
		return (1);
	}
	if (check_file(g, argv[1]))
	{
		ft_putstr_fd("Error. invalid file\n", 2);
		return (1);
	}
	if (check_content(g))
	{
		return(1);
	}
	return (0);
}

/*TODO: make the key_handler + init_game + load_sprites functions*/
int	main(int argc, char **argv)
{
	t_game	g;

	ft_memset(&g, 0, sizeof(t_game));
	//init struct
	/*we check if the input file is playable*/
	if (check_input(argc, argv, &g))
		return (1);

	//init_game(&g) || load_sprites(&g)
	//	|| render_map(&g)
	//	exit_game(&g, 1);
	//mlx_hook(g.win, 2, 1L << 0, key_handler, &g);
	//mlx_hook(g.win, 17, 0, exit_game, &g);
	//mlx_loop(g.mlx);
}