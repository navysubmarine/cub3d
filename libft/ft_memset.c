/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 09:31:15 by marthoma          #+#    #+#             */
/*   Updated: 2025/11/12 17:36:23 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned long	i;

	i = 0;
	while (i < n)
	{
		*((char *)(s + i)) = (char) c;
		i++;
	}
	return (s);
}
/*
int main()
{
	int	s[]= {42, 7, 2, 48, 1};
	int	c;
	unsigned long	n;
	
	c = 6;
	n = 5;
    printf("%d\n", (*(int *)(ft_memset(s, c, n))));
    printf("%d", (*(int *)(memset(s, c, n))));
    return(0);
}
*/
