/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansulist <ansulist@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 11:37:58 by ansulist          #+#    #+#             */
/*   Updated: 2023/04/07 13:11:42 by ansulist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

// the number is on the upper side of the list
// move it up!
// the number is on the lower side of the list
// move it down!
void	move_number_to_stack_b(t_stack **a, t_stack **b, int nb)
{
	int	len;
	int	i;

	len = ft_lstsize(*a);
	i = find_nb_pos(*a, nb);
	if (i < (len / 2))
	{
		while ((*a)->value != nb)
			rotate_a(a);
		push_b(a, b);
		return ;
	}
	while ((*a)->value != nb)
		reverse_a(a);
	push_b(a, b);
}

// Calculate how many operations to do
// to move the given number from stack a to stack b
// Number is in the upper side of the list
// Number is on the lower side of the list
int	nb_op_to_stack_b(t_stack *a, int nb)
{
	int	len;
	int	i;

	len = ft_lstsize(a);
	i = find_nb_pos(a, nb);
	if (i < len / 2)
		return (i);
	return (len - i);
}

// [1, 2, 3, 4, 5]
//     chunk
// For each number in the chunk, look how much operations are required
// to move them to stack B.
// Move the one requiring the least operations.
// Repeat until all numbers are in stack B.
// identify the number requiring least operations
// We have dealt with all numbers
// move the number to stack b
int	give_nb_index(t_stack **a, long long *array, int len)
{
	int	i;
	int	tmp;
	int	nb_op;
	int	nb_index;

	i = 0;
	nb_op = -1;
	nb_index = -1;
	while (i < len && array[i] != END)
	{
		if (array[i] != DONE)
		{
			tmp = nb_op_to_stack_b(*a, (int)array[i]);
			if (nb_op == -1 || tmp < nb_op)
			{
				nb_op = tmp;
				nb_index = i;
			}
		}
		i++;
	}
	return (nb_index);
}

void	to_stack_b(t_stack **a, t_stack **b, long long *array, int len)
{
	int	nb_index;

	while (1)
	{
		nb_index = give_nb_index(a, array, len);
		if (nb_index == -1)
			return ;
		move_number_to_stack_b(a, b, (int)array[nb_index]);
		array[nb_index] = DONE;
	}
}
