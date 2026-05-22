/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:39:55 by marthoma          #+#    #+#             */
/*   Updated: 2025/11/19 19:04:19 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//void	*allocc_and_protecc(size_t nmemb, size_t size)
//{
//	char	*new;
//	new = malloc(nmemb * size);
//
//		if (new == NULL)
//			return (NULL);
//		else
//			return (new);
//}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char			*new;
	unsigned long	i;
	unsigned long	c;

	i = 0;
	c = nmemb * size;
	if (nmemb == 0 || size == 0)
		new = malloc(0);
	else if (c / size != nmemb)
		return (0);
	else
	{
		new = malloc(nmemb * size);
		if (new == NULL)
			return (NULL);
		while (i < (size * nmemb))
		{
			new[i] = 0;
			i++;
		}
	}
	return (new);
}
/*
int	main()
{
	unsigned long	nmemb;
	unsigned long	size;
	void *ptr;

	nmemb = 0;
	size = 2;
	ptr = (unsigned long *)(ft_calloc(nmemb, size));

	printf("%p\n", ptr); 
	printf("%lu", sizeof(ptr));
	free(ptr);
//	printf("p\n", (char *)(ft_calloc(nmemb, size)));
	return (0); 
}
*/
