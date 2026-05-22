/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 14:02:25 by marthoma          #+#    #+#             */
/*   Updated: 2025/11/21 18:17:12 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
static void	weird_tolower(unsigned int i, char *s)
{
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			s[i] = s[i] + 32;
		}

}
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &(s[i]));
		i++;
	}
}
/*
int	main()
{
	char	s[]={'C', 'o', 'C', '0', 'u', '\0'};

	printf("old : %s\n", s);
	ft_striteri(s, weird_tolower);
	printf("new : %s", s);
}
*/
