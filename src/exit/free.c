/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 12:10:38 by marthoma          #+#    #+#             */
/*   Updated: 2026/06/12 15:53:48 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void safe_free(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}

void	free_content(char **content)
{
	int	i;

	if (!content)
		return ;
	i = 0;
	while (content[i])
	{
		safe_free(content[i]);
		i++;
	}
	safe_free(content);
}

void	free_parse(t_parse *p)
{
	int	i;

	free_content(p->content);
	p->content = NULL;
	i = 0;
	while (i < 4)
	{
		free(p->textures[i].path);
		p->textures[i].path = NULL;
		i++;
	}
	free_content(p->map.map);
	p->map.map = NULL;
	free_content(p->map.copy);
	p->map.copy = NULL;
	free_content(p->map.padded_copy);
	p->map.padded_copy = NULL;
}