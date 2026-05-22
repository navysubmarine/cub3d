/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 16:52:33 by marthoma          #+#    #+#             */
/*   Updated: 2025/11/15 17:04:33 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int long	i;

	if (n == -2147483648)
	{
		write (fd, "-2147483648", 11);
		return ;
	}
	i = n;
	if (i < 0)
	{
		write(fd, "-", 1);
		i = -i;
	}
	if (i > 9)
	{
		ft_putnbr_fd((i / 10), fd);
		ft_putchar_fd(((i % 10) + '0'), fd);
	}
	if (i < 10)
		ft_putchar_fd((i + '0'), fd);
}
