/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:05:06 by marthoma          #+#    #+#             */
/*   Updated: 2025/11/18 13:55:48 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned long	i;
	unsigned long	j;

	j = n - 1;
	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		if (dest <= src)
		{
			((char *)dest)[i] = ((const char *)src)[i];
		}
		else if (dest > src)
		{
			((char *)dest)[j] = ((const char *)src)[j];
			j--;
		}
		i++;
	}
	return (dest);
}
/*
int main()
{
    char s1[] = "bonjour petit crustace";
	char s2[] = "bonjour petit crustace";
	printf("%s\n", (char *)(memmove(s2, s2, 7)));
    printf("%s\n", (char *)(ft_memmove(s1, s1, 7)));
   return(0);
}
*/
