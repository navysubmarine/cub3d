/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:43:14 by marthoma          #+#    #+#             */
/*   Updated: 2025/11/10 17:06:40 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	unsigned long	i;

	i = 0;
	if (c >= 'A' && c <= 'Z')
		c = c + 32;
	return (c);
}
/*
int main()
{
    int c = '~';
    printf("%c", ft_tolower(c));
	printf("%c", tolower(c));
    return (0);
}
*/
