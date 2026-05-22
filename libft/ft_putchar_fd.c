/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 16:10:56 by marthoma          #+#    #+#             */
/*   Updated: 2025/11/21 18:16:28 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}	
/*
int	main()
{
	char	c;
	int		fd;

	c = 'i';
	fd = 0;
	ft_putchar_fd(c, fd);
	return (0);
}
*/
