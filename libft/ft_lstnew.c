/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 18:20:16 by marthoma          #+#    #+#             */
/*   Updated: 2026/01/22 14:16:01 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void	printlist(t_list *lst)
{
	t_list	*temp;

	temp = lst;
	while (temp != NULL)
	{
		printf("%s\n", (char *)temp->content);
		temp = temp->next;
	}
}
*/

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
/*
int	main(void)
{
	char	*content;

	content = "bonjour";
	// t_list    n1;
	// t_list    n2;
	// t_list    n3;
	// n1.content = "45";
	// n2.content = "78";
	// n3.content = "12";
	// n1.next = &n2;
	// n2.next = &n3;
	// n3.next = NULL;
	printlist(ft_lstnew(content));
}
*/