/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemouge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:16:33 by bdemouge          #+#    #+#             */
/*   Updated: 2025/11/25 15:17:32 by bdemouge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_putnbr(int n)
{
	long	nb;
	int		count;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		count += pf_putchar('-');
		nb *= -1;
	}
	if (nb < 10)
		count += pf_putchar(nb + '0');
	else
	{
		count += pf_putnbr(nb / 10);
		count += pf_putnbr(nb % 10);
	}
	return (count);
}

int	pf_putunsigned(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb < 10)
		count += pf_putchar(nb + '0');
	else
	{
		count += pf_putunsigned(nb / 10);
		count += pf_putunsigned(nb % 10);
	}
	return (count);
}
