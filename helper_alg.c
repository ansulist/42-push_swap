/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_alg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansulist <ansulist@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 16:14:58 by ansulist          #+#    #+#             */
/*   Updated: 2023/04/10 12:19:02 by ansulist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_nb_chunk(int len, int chunk_size)
{
	int	nb_chunks;

	nb_chunks = len / chunk_size;
	if (len % chunk_size > 0)
		nb_chunks++;
	return (nb_chunks);
}

void	move_number_to_stack_a(t_stack **a, t_stack **b, int nb)
{
	int	len;
	int	i;

	len = ft_lstsize(*b);
	i = find_nb_pos(*b, nb);
	if (i < (len / 2))
	{
		while ((*b)->value != nb)
			rotate_b(b);
		push_a(a, b);
		return ;
	}
	while ((*b)->value != nb)
		reverse_b(b);
	push_a(a, b);
}

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
