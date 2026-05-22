/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 17:41:38 by marthoma          #+#    #+#             */
/*   Updated: 2025/11/21 16:04:13 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	rev_str(char *s, size_t len)
{
	unsigned long	i;
	char			temp;

	i = 0;
	while (i < len / 2)
	{
		temp = s[len - 1 - i];
		s[len - 1 - i] = s[i];
		s[i] = temp;
		i++;
	}
}

static int	calcul_len(int n)
{
	long	nbr;
	int		v;

	v = 0;
	nbr = n;
	if (nbr < 0)
	{
		v++;
		nbr = -nbr;
	}
	while (nbr >= 10)
	{
		nbr = nbr / 10;
		v++;
	}
	return (v + 1);
}

static unsigned long	fill_in_str(int n, char *s)
{
	long			resultat;
	long			reliquat;
	unsigned long	i;

	resultat = n;
	i = 0;
	if (resultat == 0)
	{
		s[i++] = '0';
		s[i] = '\0';
	}
	if (resultat < 0)
		resultat = -resultat;
	while (resultat != 0)
	{	
		reliquat = resultat % 10;
		s[i] = reliquat + '0';
		resultat = resultat / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char			*s;
	unsigned long	i;
	long			v;

	i = 0;
	v = calcul_len(n);
	s = malloc(sizeof(char) * (v + 1));
	if (!s)
		return (NULL);
	i = fill_in_str(n, s);
	if (n < 0)
		s[i++] = '-';
	s[i] = '\0';
	rev_str(s, i);
	return (s);
}
/*
int	main()
{
	int	n;
//	char	s[]={'1', '0', '0', '4', '\0'};
	n = -2147483648;
	printf("%s", ft_itoa(n));
	return(0);
}
*/
