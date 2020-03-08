/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:31:09 by asoursou          #+#    #+#             */
/*   Updated: 2020/03/08 19:19:37 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "comb.h"

/*
** Utilisation:
** Le programme prend en argument 2 paramètres.
** Le premier est k et le deuxième n.
** Il affiche ensuite toutes les combinaisons possibles de k parmi n
*/

// Génère récursivement l'arbre de combinaisons
t_node	*gen_combinations(char **tab, int i, int k, int n)
{
	t_node	*t;
	t_node	*t2;
	int		j;

	if (n == 1)
		return (new_node(tab[i]));
	if (k == 1 || (k == n))
	{
		t = new_node(k == 1 ? "+" : ".");
		for (j = 0; j < n; ++j)
			push(&t->children, new_list(new_node(tab[i + j])));
		return (t);
	}
	t = new_node("+");
	for (j = 0; j < n - k; ++j)
	{
		t2 = new_node(".");
		push(&t->children, new_list(t2));
		push(&t2->children, new_list(new_node(tab[i + j])));
		push(&t2->children, new_list(gen_combinations(tab, i + j + 1, k - 1, n - j - 1)));
	}
	push(&t->children, new_list(gen_combinations(tab, i + n - k, k, k)));
	return (t);
}

// Prépare un tableau de noeuds événements avant la génération de l'arbre
t_node	*gen_combinations_tree(int k, int n)
{
	char	**tab;
	t_node	*tree;
	int		i;

	if (n < 1 || n > MAX || k < 1 || k > n) // Vérification des bornes
		EXIT_MALLOC(EINVAL);
	SAFE_MALLOC(tab, n * sizeof(char*));
	for (i = 0; i < n; ++i)
	{
		SAFE_MALLOC(tab[i], (STRMAX + 1) * sizeof(char));
		snprintf(tab[i], STRMAX, "%c", i + 'a');
	}
	tree = gen_combinations(tab, 0, k, n);
	for (i = 0; i < n; ++i)
		free(tab[i]);
	free(tab);
	return (tree);
}

// Entrée du programme
int		main(int ac, char **av)
{
	t_node	*tree;
	int		k, n;

	if (ac == 3) // Récupère les paramètres k et n
	{
		k = atoi(av[1]);
		n = atoi(av[2]);
		tree = gen_combinations_tree(k, n);
		print_tree(tree, 0);
		delete_tree(tree);
	}
	else
		printf("usage: %s [k] [n]\n", av[0]);
	return (0);
}
