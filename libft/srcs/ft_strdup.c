/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemouge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 10:26:04 by bdemouge          #+#    #+#             */
/*   Updated: 2025/11/10 14:06:05 by bdemouge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;

	dup = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (dup == NULL)
		return (NULL);
	ft_strlcpy(dup, s, ft_strlen(s) + 1);
	return (dup);
}
/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char	*src;
	char	*ft_dup;
	char	*dup;

	src = "asjfkdsfjkgjhsfjdghjksdfhgljsdfhjkghsdkljhgsjkdfhglskdjksjeiouergj";
	ft_dup = ft_strdup(src);
	dup = strdup(src);
	printf("%s\n", ft_dup);
	printf("%s\n", dup);
	free(ft_dup);
	free(dup);
	return(0);
}
*/
