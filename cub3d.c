/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 11:46:19 by marthoma          #+#    #+#             */
/*   Updated: 2026/05/22 18:54:22 by marthoma         ###   ########.fr       */
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

char	**store_content(t_game *g, char *file, int nb_of_lines)
{
	char	**content;
	int		fd;
	int		i;
	char	*eol;

	(void)g;
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
	//TODO: add a free "content" in case of error
		if (!content[i])
			return (close(fd), NULL);
		if (ft_strchr(content[i], '\n'))
		{
			eol = ft_strchr(content[i], '\n');
			*eol = '\0';
		}
		i++;
	}
	return (content[i] = NULL, close(fd), content);
}

static int	check_file(t_game *g, char *filename)
{
	int	fd;
	int	nb_of_lines;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	nb_of_lines = count_lines(fd);
	g->file.content = store_content(g, filename, nb_of_lines);
	return (fd);
}

/*TODO: make check map function*/\
// int	check_map(t_game *g, char *filename)
// {

// }

int	check_input(int argc, char **argv, t_game *g)
{
	if (argc != 2 || !ft_strchr_cub(argv[1]))
	{
		ft_putstr_fd("Error. Correct input format : ./cub3d <filename>.cub\n",
			2);
		return (1);
	}
	check_file(g, argv[1]);
	//check_textures;
	//check_colors;
	//check_map(g, argv[1]);
	return (0);
}

/*TODO: make the key_handler + init_game + load_sprites functions*/
int	main(int argc, char **argv)
{
	t_game	g;

	ft_memset(&g, 0, sizeof(t_game));
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