/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemouge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 11:20:12 by bdemouge          #+#    #+#             */
/*   Updated: 2025/11/13 11:27:53 by bdemouge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
void	test(unsigned int i, char *s)
{
	*s += i;
}
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}
/*
#include <stdio.h>

int	main(void)
{
	char	s[] = "0123";

	ft_striteri(s, &test);
	printf("%s\n", s);
	return (0);
}
*/
