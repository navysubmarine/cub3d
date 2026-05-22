/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 09:57:19 by marthoma          #+#    #+#             */
/*   Updated: 2025/11/10 11:22:49 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned long	i;

	(void) n;
	i = 0;
	while (n > i)
	{
		(((char *)s)[i]) = '\0';
		i++;
	}
}
/*
int	main()
{
 	char str[] = "coucou";
	
    ft_bzero(str, 3);
//  printf("%s", str);
    return (0);
//	printf("%c", (((char*)s)[i+1]));
}
*/
