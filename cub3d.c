/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 11:46:19 by marthoma          #+#    #+#             */
/*   Updated: 2026/05/25 16:38:22 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
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
*/
char	**store_content(char *file, int nb_of_lines)
{
	char	**content;
	char	*line;
	char	*tmp;
	int		fd;
	int		i;

	i = 0;
	content = ft_strdup("");
	if (!content)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (free(content), NULL);
	while (i < nb_of_lines)
	{
		line = get_next_line(fd);
		if (!line)
			return (close(fd), free(content), NULL);
		tmp = ft_strjoin(content, line);
		free(content);
		free(line);
		if (!tmp)
			return (close(fd), NULL);
		content = tmp;
		i++;
	}
	close(fd);
	return (content);
}

static int	check_file(t_game *g, char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	g->file.nb_of_lines = count_lines(fd);
	g->file.content = store_content(filename, g->file.nb_of_lines);
	close(fd);
	return (0);
}


/*TODO: make check map function*/\
// int	check_map(t_game *g, char *filename)
// {

// }

int	check_textures(t_game *g)
{
	char	*f_content;

	f_content = g->file.content;
	g->file.path_no_texture = ft_strnstr(f_content, "NO ./", 6) + 5;
	if (!g->file.path_no_texture)
	{
		ft_putstr_fd("Error. Incorrect North texture\n", 33);
		return (1);
	}
	
}

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

int	is_valid_map_line(char	*line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '0' && line[i] != '1'
			&& line[i] != 'N' && line[i] != 'S'
			&& line[i] != 'E' && line[i] != 'W'
			&& line[i] != ' ' && line[i] != 9)
		{
			ft_putstr_fd("Error. Invalid character in map\n", 2);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_content(t_game *g)
{
	int	i;
	char **lines;
	
	i = 0;
	g->file.content = lines; 
	while (i < g->file.nb_of_lines && !is_ valid_map_line(lines[i]))
	{
		//
	}

	while (i < g->file.nb_of_lines)
	{
		
	}

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
	if (check_content(g, argv[1]))
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
	if (check_input(argc, argv, &g))
	// || 
	//init_game(&g) || load_sprites(&g)
	//	|| render_map(&g)
	//	exit_game(&g, 1);
		return (1);
	//mlx_hook(g.win, 2, 1L << 0, key_handler, &g);
	//mlx_hook(g.win, 17, 0, exit_game, &g);
	//mlx_loop(g.mlx);
}