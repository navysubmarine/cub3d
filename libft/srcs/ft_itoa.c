/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemouge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:17:48 by bdemouge          #+#    #+#             */
/*   Updated: 2025/11/13 10:56:14 by bdemouge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

static int	count_char(long n)
{
	int	count;

	count = 0;
	if (n <= 0)
	{
		count++;
		n *= -1;
	}
	while (n > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nbr;
	int		min;
	int		max;

	nbr = n;
	min = 0;
	max = count_char(nbr);
	str = malloc(sizeof(char) * (max + 1));
	if (str == NULL)
		return (NULL);
	if (nbr < 0)
	{
		str[min++] = '-';
		nbr *= -1;
	}
	str[max--] = '\0';
	while (max >= min)
	{
		str[max--] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (str);
}
/*
int	main(int ac, char **av)
{
	char	*str;

	if (ac == 2)
	{
		str = ft_itoa(atoi(av[1]));
		printf("%s", str);
		free(str);
	}
	return (0);
}
*/
