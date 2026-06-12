/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemouge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:06:49 by bdemouge          #+#    #+#             */
/*   Updated: 2025/11/25 15:08:25 by bdemouge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	pf_putstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (pf_putstr("(null)"));
	while (s[i])
	{
		pf_putchar(s[i]);
		i++;
	}
	return (i);
}
