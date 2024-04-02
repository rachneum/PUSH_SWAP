/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rachou <rachou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:11:05 by rachou            #+#    #+#             */
/*   Updated: 2024/04/02 14:13:15 by rachou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_last_node(t_stack *stack)
{
    if (!stack)
        return (NULL);
    while (stack->next)// Boucle jusqu'à ce que la fin de la pile soit atteinte.
        stack = stack->next;
    return (stack);
}
int	stack_len(t_stack *stack)//Permet de calculer la longuer de ma stack et me sevira plus tard pour ma médiane.
{
	int	count;

	if (stack == NULL)
		return (0);
	count = 0;
	while (stack)
	{
		++count;
		stack = stack->next;
	}
	return (count);
}

void	index(t_stack_node *stack)
{
	int	i;
	int	median;

	i = 0;
	median = (stacklen(stack) / 2);
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->median = true;
		else
			stack->median = false;
		stack = stack->next;
		i++;
	}
}

t_stack	*find_min(t_stack *stack)//Recherche une pile et renvoie le noeud avec le plus petit nombre.
{
	long	min;//Pour stocker la plus petite valeur jusqu'à présent.
	t_stack	*min_node;//Pour stocker un pointeur pointant vers le plus petit nombre.

	if (!stack)
		return (NULL);
	min = LONG_MAX;//Attribue à la plus petite valeur jusqu'à présent, l'entier long maximum.
	while (stack)
	{
		if (stack->value < min)//Vérifie si la valeur actuelle du noeud est inférieure à la plus petite jusqu'à présent.
		{
			min = stack->value;//Si c'est le cas, mettre à jour le plus petit nombre jusqu'à présent.
			min_node = stack;//Définit le pointeur pour qu'il pointe vers le noeud avec le plus petit nombre jusqu'à présent.
		}
		stack = stack->next;
	}
	return (min_node); 
}

t_stack	*find_max(t_stack *stack)//Recherche une pile et renvoie le noeud avec le plus grand nombre.
{
	long	max;//Pour stocker la plus grande valeur jusqu'à présent.
	t_stack	*max_node;//Pour stocker un pointeur qui pointe vers le plus grand nombre.

	if (!stack)
		return (NULL);
	max = LONG_MIN;//Attribue à la plus grande valeur jusqu'à présent, l'entier long maximum.
	while (stack)
	{
		if (stack->value > max)//Vérifie si la valeur actuelle du noeud est inférieure à la plus grande jusqu'à présent.
		{
			max = stack->value;//Si c'est le cas, mettre à jour le plus grand nombre jusqu'à présent.
			max_node = stack;//Définit le pointeur pour qu'il pointe vers le noeud avec le plus grand nombre jusqu'à présent.
		}
		stack = stack->next;
	}
	return (max_node);
}
