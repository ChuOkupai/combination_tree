/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 13:43:15 by asoursou          #+#    #+#             */
/*   Updated: 2020/03/08 14:04:01 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "comb.h"

t_list	*new_list(t_node *n)
{
	t_list *l;

	SAFE_MALLOC(l, sizeof(t_list));
	l->content = n;
	l->next = NULL;
	return (l);
}

void	push(t_list **l, t_list *elem)
{
	elem->next = *l;
	*l = elem;
}

t_node	*pop(t_list **l)
{
	t_list	*e;
	t_node	*n;

	e = *l;
	n = e->content;
	*l = (*l)->next;
	free(e); // On supprime le premier élément de la liste en mémoire
	return (n);
}
