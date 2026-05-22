/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 18:36:34 by marthoma          #+#    #+#             */
/*   Updated: 2026/01/22 14:15:31 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*
void	first_letter_upper(void  *content)
{
	char	*str;

	str = content;
	*str = toupper(*str);
}

int	main(void)
{
	t_list	*list;
	t_list	*node1;
	t_list	**lst;
	t_list	*node2;
	t_list	*node3;
	t_list	*current;
	t_list	*tmp;

	list = NULL;
	// Ajouter des éléments à la liste chaînée
	node1 = (t_list *)malloc(sizeof(t_list));
	node1->content = strdup("Bonjour");
	node1->next = NULL;
	list = node1;  // Premier élément de la liste
	lst = &list;
	node2 = (t_list *)malloc(sizeof(t_list));
	node2->content = strdup("petit");
	node2->next = NULL;
	node1->next = node2;  // On lie node2 après node1
	node3 = (t_list *)malloc(sizeof(t_list));
	node3->content = strdup("crustace");
	node3->next = NULL;
	node2->next = node3;  // On lie node3 après node2
	ft_lstiter(*lst, randomi);
	current = list;
	// Afficher la liste chaînée
	while (current)
	{
		printf("%s\n", (char *)current->content);
			// Afficher le contenu de chaque noeud
		current = current->next; // Passer au noeud suivant
	}
	while (list)
	{
		tmp = list->next;
		free(list->content);
		free(list);
		list = tmp;
	}
	return (0);
}
*/