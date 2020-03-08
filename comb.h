/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comb.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 13:39:59 by asoursou          #+#    #+#             */
/*   Updated: 2020/03/08 16:37:21 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMB_H
# define COMB_H
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

// Limite (sinon il y a trop de combinaisons possible)
#define MAX 12

// Longueur maximum des chaînes de caractères
#define STRMAX 12

// Pour simplifier le code
// Ne pas utiliser pour un vrai projet !
#define EXIT_MALLOC(ERRNUM)	{ \
	fprintf(stderr, "error: %s\n", strerror((int)(ERRNUM))); \
	exit((int)(ERRNUM)); \
}

// Pour simplifier la gestion des mallocs qui foirent
// Ne pas utiliser pour un vrai projet !
#define SAFE_MALLOC(VARIABLE, SIZE)	\
	if (!((VARIABLE) = malloc((SIZE)))) exit(errno);

typedef struct s_list	t_list;
typedef struct s_node	t_node;

// Définition d'une liste de noeuds (notamment pour les fils)
struct s_list
{
	t_node	*content;
	t_list	*next;
};

// Définition d'un noeud générique avec un attribut name juste pour les tests
struct s_node
{
	char	name[STRMAX + 1];
	t_list	*children;
};

// Création d'un nouveau élément de liste
t_list	*new_list(t_node *n);

// Ajoute un élément au début de la liste
void	push(t_list **l, t_list *elem);

// Détruit le premier élément de la liste
t_node	*pop(t_list **l);

// Création d'un nouveau noeud
t_node	*new_node(const char *name);

// Affiche un arbre
void	print_tree(t_node *n, int deep);

// Supprime un arbre en mémoire
void	delete_tree(t_node *n);

#endif
