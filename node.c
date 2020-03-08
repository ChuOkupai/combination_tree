/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 13:44:03 by asoursou          #+#    #+#             */
/*   Updated: 2020/03/08 16:37:15 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "comb.h"

t_node	*new_node(const char *name)
{
	t_node *n;

	SAFE_MALLOC(n, sizeof(t_node));
	strncpy(n->name, name, STRMAX); // Evite les segfaults (buffer overflow)
	n->children = NULL;
	return (n);
}

void	print_tree(t_node *n, int deep)
{
	t_list *l;

	if (!n)
		return ;
	for (int i = 0; i < deep - 1; ++i)
		printf("  ");
	if (deep++)
		printf("↳ ");
	printf("%s\n", n->name);
	l = n->children;
	while (l) // Pour tous les fils
	{
		print_tree(l->content, deep);
		l = l->next;
	}
}

void	delete_tree(t_node *n)
{
	if (!n)
		return ;
	while (n->children) // Pour tous les fils
	{
		delete_tree(n->children->content);
		pop(&n->children);
	}
	free(n);
}
