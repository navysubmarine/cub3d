/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemouge <bdemouge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 09:56:14 by bdemouge          #+#    #+#             */
/*   Updated: 2026/06/26 15:00:27 by bdemouge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	clean_stash(char **stash)
{
	if (*stash)
	{
		free(*stash);
		*stash = NULL;
	}
}

static int	get_nl_index(char *str)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return (-1);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return (i);
	return (-1);
}

static int	update_stash(char **stash, char *buffer)
{
	char	*new_stash;

	if (!*stash)
		*stash = ft_strdup("");
	if (!*stash)
		return (0);
	new_stash = ft_strjoin(*stash, buffer);
	if (!new_stash)
		return (clean_stash(stash), 0);
	free(*stash);
	*stash = new_stash;
	return (1);
}

static char	*extract_line(char **stash)
{
	char	*new_stash;
	char	*line;
	int		idx;

	if (!*stash || !**stash)
		return (clean_stash(stash), NULL);
	idx = get_nl_index(*stash);
	if (idx != -1)
	{
		new_stash = ft_substr(*stash, idx + 1, ft_strlen(*stash) - idx - 1);
		if (!new_stash)
			return (clean_stash(stash), NULL);
		line = ft_substr(*stash, 0, idx + 1);
		if (!line)
			return (free(new_stash), clean_stash(stash), NULL);
		free(*stash);
		*stash = new_stash;
		return (line);
	}
	line = ft_strdup(*stash);
	return (free(*stash), *stash = NULL, line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;
	int			count_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (clean_stash(&stash), NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (clean_stash(&stash), NULL);
	count_read = 0;
	while (get_nl_index(stash) < 0)
	{
		count_read = read(fd, buffer, BUFFER_SIZE);
		if (count_read <= 0)
			break ;
		buffer[count_read] = '\0';
		if (!update_stash(&stash, buffer))
			return (free(buffer), NULL);
	}
	free(buffer);
	if (count_read == -1)
		return (clean_stash(&stash), NULL);
	return (extract_line(&stash));
}
