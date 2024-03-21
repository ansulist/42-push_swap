/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansulist <ansulist@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 00:21:58 by ansulist          #+#    #+#             */
/*   Updated: 2023/04/10 12:11:30 by ansulist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	*list_to_tab(t_stack **stack)
{
	t_stack		*a;
	long long	*values;
	int			i;

	if (stack == NULL || ft_lstsize(*stack) <= 0)
		return (NULL);
	a = *stack;
	i = 0;
	values = malloc(sizeof(long long) * (ft_lstsize(*stack) + 1));
	while (a->next != NULL)
	{
		values[i] = (long long)a->value;
		a = a->next;
		i++;
	}
	values[i] = (long long)a->value;
	values[i + 1] = END;
	return (values);
}

void	ft_sort_long_long_tab(long long *tab)
{
	int	i;
	int	temp;

	i = 0;
	while (tab[i] != END)
	{
		if (tab[i] > tab[i + 1])
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = -1;
		}
		i++;
	}
}

int	find_nb_pos(t_stack *a, int nb)
{
	int	i;

	i = 0;
	while (a->value != nb)
	{
		i++;
		a = a->next;
	}
	return (i);
}
