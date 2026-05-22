/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:50:34 by marthoma          #+#    #+#             */
/*   Updated: 2025/11/21 18:18:33 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned long		i;
	unsigned long		j;
	unsigned long		longueur_big;

	i = 0;
	j = 0;
	longueur_big = ft_strlen(big);
	if (little[i] == '\0')
		return (((char *)big));
	while (j < longueur_big && j < len)
	{
		if (little[i] == big[j])
		{
			while (big[j + i] != '\0' && little[i] == big[j + i]
				&& (j + i) < len)
			{
				i++;
				if (little[i] == '\0')
					return (&(((char *)big)[j]));
			}
		}
		i = 0;
		j++;
	}
	return (0);
}
/*
int main()
{
	char s1[]="aaabcabcdd";
//	char s2[]="aabc";

//	printf("%s\n", s1);
	printf("%s\n", ft_strnstr(s1, "cd", 8));
	printf("%s\n", strnstr(s1, "cd", 8));
	return (0);
}
*/
