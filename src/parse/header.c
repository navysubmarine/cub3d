/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemouge <bdemouge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 15:49:37 by marthoma          #+#    #+#             */
/*   Updated: 2026/06/09 17:31:24 by bdemouge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	validate_header_set(t_file *file)
{
	if (!file->path_no)
		return (ft_putstr_fd("Error. Missing north texture\n", 2), 1);
	if (!file->path_so)
		return (ft_putstr_fd("Error. Missing south texture\n", 2), 1);
	if (!file->path_we)
		return (ft_putstr_fd("Error. Missing west texture\n", 2), 1);
	if (!file->path_ea)
		return (ft_putstr_fd("Error. Missing east texture\n", 2), 1);
	if (file->floor_set == FALSE)
		return (ft_putstr_fd("Error. Missing floor color\n", 2), 1);
	if (file->ceiling_set == FALSE)
		return (ft_putstr_fd("Error. Missing ceiling color\n", 2), 1);
	return (0);
}
