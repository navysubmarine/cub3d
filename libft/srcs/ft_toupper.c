/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemouge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 09:23:04 by bdemouge          #+#    #+#             */
/*   Updated: 2025/11/10 09:45:18 by bdemouge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
/*
#include <ctype.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		printf("av = %c\n", av[1][0]);
		printf("ft_toupper = %c\n", ft_toupper(av[1][0]));
		printf("toupper = %c\n", toupper(av[1][0]));
		printf("av = %c\n", av[1][0]);
	}
	return 0;
}
*/
