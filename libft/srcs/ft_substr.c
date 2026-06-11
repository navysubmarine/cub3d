/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemouge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 10:21:28 by bdemouge          #+#    #+#             */
/*   Updated: 2025/11/14 14:37:57 by bdemouge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;

	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	else if (ft_strlen(&s[start]) < len)
		return (ft_strdup(&s[start]));
	else
	{
		substr = malloc(sizeof(char) * (len + 1));
		if (substr == NULL)
			return (NULL);
		ft_strlcpy(substr, &s[start], len + 1);
		return (substr);
	}
}

/*
#include <stdio.h>

int	main(void)
{
	char	*substr;

	substr = ft_substr("tripouille", 100, 1);
	printf("%d\n", substr[0]);
	free(substr);
	return (0);
}
*/
