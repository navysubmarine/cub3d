/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 11:46:19 by marthoma          #+#    #+#             */
/*   Updated: 2026/05/26 17:11:44 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*match_content(char *line, char *id)
{
	int	len;
	int	i;

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

static int	handle_file(t_game *g, char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (1);
	g->file.nb_of_lines = count_lines(fd);
	g->file.content = store_content(filename, g->file.nb_of_lines);
	return (0);
}

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

int	map_line_detector(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == '0' || line[i] == '1')
		return (TRUE);
	else
		return (FALSE);
}

int	test_tx_path(char *tx_type, char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		printf("Error. %s texture has invalid pathname\n", tx_type);
		return (1);
	}
	close (fd);
	return (0);
}

int	test_rgb_format(char *content)
{
	int	i;
	int	comma_nb;

	i = 0;
	comma_nb = 0;
	while (content[i])
	{
		if (content[i] == ',')
			comma_nb++;
		else if (content[i] < '0' || content[i] > '9')
		{
			return (1);
		}
		i++;
	}
	if (comma_nb != 2)
		return (1);
	return (0);
}

int	test_rgb_color(char	*id, char *content)
{
	char	**tab;
	int		i;

	i = 0;
	if (test_rgb_format(content))
	{
		printf("Error. %s color of invalid format\n", id);
		return (1);
	}
	tab = ft_split(content, ',');
	if (!tab)
	{
		ft_putstr_fd("Error. Ft_split failed\n", 2);
		return (1);
	}
	while (tab[i])
	{
		if (ft_atoi(tab[i]) > 255 || ft_atoi(tab[i]) < 0)
		{
			ft_putstr_fd("Error. RGB number is out of bound\n", 2);
			free_content(tab);
			return (1);
		}
		i++;
	}
	free_content(tab);
	return (0);
}

int	store_rgb(int *values, char *content)
{
	char	**tab;
	int		i;

	i = 0;
	tab = ft_split(content, ',');
	if (!tab)
	{
		ft_putstr_fd("Error. Ft_split failed\n", 2);
		return (1);
	}
	while (i < 3)
	{
		values[i] = ft_atoi(tab[i]);
		i++;
	}
	free_content(tab);
	return (0);
}

int	validate_texture_line(char	*line, t_game *g)
{
	char	*content;
	/*TODO: blank is not an error - handle differently*/
	if (!line || line[0] == '\0' || line[0] == '\n' || line[0]== '\t')
		return (1);

	if (ft_strncmp(line, "NO ", 3) == 0 && line[3] != '\0')
	{
		content = match_content(line, "NO");
		if (test_tx_path("North", content))
			return (1);
		else
		{
			if (set_var(&g->file.path_no, content))
				return (1);
		}
	}
	else if (ft_strncmp(line, "SO ", 3) == 0 && line[3] != '\0')
	{
		content = match_content(line, "SO");
		if (test_tx_path("South", content))
			return (1);
		else
		{
			if (set_var(&g->file.path_so, content))
				return (1);
		}
	}
	else if (ft_strncmp(line, "WE ", 3) == 0 && line[3] != '\0')
	{
		content = match_content(line, "WE");
		if (test_tx_path("West", content))
			return (1);
		else
		{
			if (set_var(&g->file.path_we, content))
				return (1);
		}
	}
	else if (ft_strncmp(line, "EA ", 3) == 0 && line[3] != '\0')
	{
		content = match_content(line, "EA");
		if (test_tx_path("East", content))
			return (1);
		else
		{
			if (set_var(&g->file.path_ea, content))
				return (1);
		}
	}
	return (0);
}

int	validate_color_line(char	*line, t_game *g)
{
	char	*content;

	if (ft_strncmp(line, "F ", 2) == 0 && line[2] != '\0')
	{
		content = match_content(line, "F");
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
	else if (ft_strncmp(line, "C ", 2) == 0 && line[2] != '\0')
	{
		content = match_content(line, "C");
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
		print_file(file);
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
	/*0=yes it's a texture line, 1=no*/
	if (ft_strncmp(line, "NO ", 3) == 0)
		return (0);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		return (0);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		return (0);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		return (0);
	else
		return (1);
}

int	color_line_detector(char *line)
{
	/*0=yes it's a color line, 1=no*/
	if (ft_strncmp(line, "F ", 2) == 0)
		return (0);
	else if (ft_strncmp(line, "C ", 2) == 0)
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
		else if (texture_line_detector(lines[i]) == TRUE)
		{
			if (validate_texture_line(lines[i], g))
				return (1);
		}
		else if (color_line_detector(lines[i]) == TRUE)
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
			break ;
		}
		else
		{
			print_file(&g->file);
			printf("DEBUG unrecognized line [%d]: '%s'\n", i, lines[i]);
			ft_putstr_fd("Error. Unrecognized line\n", 2);
			return (1);
		}
		i++;
	}
	/*TODO: add validate_all_map_set*/
	if (validate_all_header_set(&g->file))
		return (1);
	print_file(&g->file);
	ft_putstr_fd("OK, file is valid. Ready to launch !!\n", 1);
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