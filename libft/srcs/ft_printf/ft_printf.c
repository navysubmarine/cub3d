/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemouge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:59:11 by bdemouge          #+#    #+#             */
/*   Updated: 2025/12/03 15:34:29 by bdemouge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	print_arg(char c, va_list pa);

int	ft_printf(const char *format, ...)
{
	int			i;
	va_list		pa;
	int			count;

	va_start(pa, format);
	i = 0;
	count = 0;
	if (!format)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (!format[i])
				return (-1);
			count += print_arg(format[i], pa);
		}
		else
			count += pf_putchar(format[i]);
		i++;
	}
	va_end(pa);
	return (count);
}

static int	print_arg(char c, va_list pa)
{
	int	count;

	count = 0;
	if (c == '%')
		count += pf_putchar('%');
	else if (c == 'c')
		count += pf_putchar((char)va_arg(pa, int));
	else if (c == 's')
		count += pf_putstr((char *)va_arg(pa, char *));
	else if (c == 'd' || c == 'i')
		count += pf_putnbr((int)va_arg(pa, int));
	else if (c == 'p')
		count += pf_putad((unsigned long long)va_arg(pa, unsigned long long));
	else if (c == 'u')
		count += pf_putunsigned((unsigned int)va_arg(pa, unsigned int));
	else if (c == 'x')
		count += pf_puthexa_lower((unsigned int)va_arg(pa, unsigned int));
	else if (c == 'X')
		count += pf_puthexa_upper((unsigned int)va_arg(pa, unsigned int));
	else
		count += ft_printf("%%%c", c);
	return (count);
}
