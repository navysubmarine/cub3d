/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 15:09:39 by marthoma          #+#    #+#             */
/*   Updated: 2026/06/12 14:20:50 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**store_content(char *file, int nb_of_lines)
{
	char	**content;
	int		fd;
	int		i;
	char	*eol;

	i = 0;
	content = ft_calloc(nb_of_lines + 1, sizeof(char *));
	if (!content)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (free(content), content = NULL, NULL);
	while (i < nb_of_lines)
	{
		content[i] = get_next_line(fd);
		if (!content[i])
			return (free_content(content), content = NULL, close(fd), NULL);
		eol = ft_strchr(content[i], '\n');
		if (eol)
			*eol = '\0';
		i++;
	}
	return (content[i] = NULL, close(fd), content);
}
