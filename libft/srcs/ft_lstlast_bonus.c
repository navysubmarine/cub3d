/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemouge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:59:58 by bdemouge          #+#    #+#             */
/*   Updated: 2025/11/17 10:20:06 by bdemouge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp;

	temp = lst;
	if (temp == NULL)
		return (NULL);
	while (temp->next)
		temp = temp->next;
	return (temp);
}
/*
#include <stdio.h>

int main(void)
{
    t_list  n1;
    t_list  n2;
    t_list  n3;
    t_list  n4;
	t_list	*test;

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = NULL;
	test = NULL;
    printf("%p\n", ft_lstlast(test));
    return (0);
}
*/
