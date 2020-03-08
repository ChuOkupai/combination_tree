/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:31:09 by asoursou          #+#    #+#             */
/*   Updated: 2020/03/08 17:26:18 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Commande pour compiler:
** $> gcc -Wall -Wextra -Werror -Ofast comb.c list.c node.c -o comb
**
** Utilisation:
** Le programme prend en argument 2 paramètres.
** Le premier est k et le deuxième n.
** Il affiche ensuite toutes les combinaisons possibles de k parmi n
**
** Exemple:
** $> ./comb 2 4
** 1 2
** 1 3
** 1 4
** 2 3
** 2 4
** 3 4
**
** Pour compter le nombre de possiblités, on peut utiliser la command wc:
** $> ./comb 2 4 | wc -l
** 6
*/

#include "comb.h"

// Génère récursivement l'arbre de combinaisons
t_node	*gen_combinations(char (*tab)[STRMAX + 1], int i, int k, int n)
{
	t_node	*t;
	t_node	*t2;
	int		j;

	t = new_node("+");
	for (j = i; j < n - k; ++j)
	{
		t2 = new_node(".");
		push(&t->children, new_list(t2));
		push(&t2->children, new_list(new_node(tab[j])));
		push(&t2->children, new_list(new_node("?")));
	}
	return (t);
}

// Prépare un tableau de noeuds événements avant la génération de l'arbre
t_node	*gen_combinations_tree(int k, int n)
{
	char	(*tab)[STRMAX + 1];
	t_node	*tree;

	if (n < 1 || n > MAX || k < 1 || k > n) // Vérification des bornes
		EXIT_MALLOC(EINVAL);
	SAFE_MALLOC(tab, n * sizeof(char*));
	for (int i = 0; i < n; ++i)
		snprintf(tab[i], STRMAX, "%c", i + 'a');
	tree = gen_combinations(tab, 0, k, n);
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
