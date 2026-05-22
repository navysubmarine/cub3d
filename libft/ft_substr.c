/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:16:31 by marthoma          #+#    #+#             */
/*   Updated: 2025/11/21 18:19:24 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	smaller(unsigned long len, char const *s, unsigned int start)
{
	if (len <= ft_strlen(s + start))
		return (len);
	return (ft_strlen(s + start));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned long	i;
	unsigned long	j;
	char			*new;
	unsigned long	new_len;

	i = start;
	j = 0;
	if (start >= ft_strlen(s))
	{
		new = ft_calloc(1, 1);
		if (!new)
			return (NULL);
		return (new);
	}
	new_len = smaller(len, s, start);
	new = malloc(sizeof(char) * new_len + 1);
	if (!new)
		return (NULL);
	while (j < new_len)
		new[j++] = s[i++];
	new[j] = '\0';
	return (new);
}
/*
int	main()
{
	char const *s;
	unsigned int	start;
	size_t	len;
	char *ptr;

	s = "bonjour petit crustace";
	start = 8;
	len = 18;
	ptr = ft_substr(s, start, len);
	
	printf("%s", ptr);
	free(ptr);
	return (0);
}
*/
