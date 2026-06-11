/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemouge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:08:46 by bdemouge          #+#    #+#             */
/*   Updated: 2025/11/25 15:09:28 by bdemouge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_puthexa_lower(unsigned long long nb)
{
	char	*base;
	int		count;

	base = "0123456789abcdef";
	count = 0;
	if (nb < 16)
		count += pf_putchar(base[nb]);
	else
	{
		count += pf_puthexa_lower(nb / 16);
		count += pf_puthexa_lower(nb % 16);
	}
	return (count);
}

int	pf_puthexa_upper(unsigned long long nb)
{
	char	*base;
	int		count;

	base = "0123456789ABCDEF";
	count = 0;
	if (nb < 16)
		count += pf_putchar(base[nb]);
	else
	{
		count += pf_puthexa_upper(nb / 16);
		count += pf_puthexa_upper(nb % 16);
	}
	return (count);
}

int	pf_putad(unsigned long long ad)
{
	int	count;

	count = 0;
	if (ad == 0)
		return (pf_putstr("(nil)"));
	count += pf_putstr("0x");
	count += pf_puthexa_lower(ad);
	return (count);
}
