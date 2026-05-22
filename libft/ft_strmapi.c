/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 11:29:45 by marthoma          #+#    #+#             */
/*   Updated: 2025/11/21 18:18:04 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
static char	weird_tolower(unsigned int i, char c)
{
	(void) i;
	if (c >= 'A' && c <= 'Z')
	{
		c = c + 32;
		return (c);
	}
	else 
		return (c);
}
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	size_t			len_s;
	char			*new;

	i = 0;
	len_s = ft_strlen(s);
	new = malloc(sizeof(char) * len_s + 1);
	if (!new)
		return (NULL);
	while (s[i])
	{
		new[i] = f(i, s[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}
/*
int	main()
{
	char const		*s;

	s = "COUCOU BANDE DE NOUILLES";
	printf("%s\n", ft_strmapi(s, weird_tolower));
}
*/	
