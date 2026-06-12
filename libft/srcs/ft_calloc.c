/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemouge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:11:29 by bdemouge          #+#    #+#             */
/*   Updated: 2025/11/12 15:04:40 by bdemouge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	a;

	if (nmemb != 0 && size != 0)
	{
		a = nmemb * size;
		if (a / size != nmemb)
			return (NULL);
	}
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
/*
#include <stdio.h>
#include <limits.h>
#include <strings.h>
#include <stdint.h>

int main(void)
{
    char    *str;

	printf("SIZE_MAX = %lu\n", SIZE_MAX);
	str = ft_calloc(SIZE_MAX, SIZE_MAX);
	printf("%p\n", str);
	free(str);
    return(0);
}
*/
