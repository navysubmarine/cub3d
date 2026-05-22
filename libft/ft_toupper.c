/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:26:58 by marthoma          #+#    #+#             */
/*   Updated: 2025/11/10 15:38:36 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	unsigned long	i;

	i = 0;
	if (c >= 'a' && c <= 'z')
			c = c - 32;
	return (c);
}
/*
int main()
{
    int c = '7';
    printf("%c", ft_toupper(c));
    return (0);
}
*/
