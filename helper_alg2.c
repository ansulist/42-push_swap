/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_alg2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansulist <ansulist@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 16:17:02 by ansulist          #+#    #+#             */
/*   Updated: 2023/04/10 14:20:12 by ansulist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	c_to_stack_a(t_stack **a, t_stack **b, long long *array, int len)
{
	int	nb_index;

	while (1)
	{
		nb_index = give_nb_index(b, array, len);
		if (nb_index == -1)
			return ;
		move_number_to_stack_a(a, b, (int)array[nb_index]);
		array[nb_index] = DONE;
	}
}

void	c_to_stack_b(t_stack **a, t_stack **b, long long *array, int len)
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

// Move all numbers inside of the chunk back to stack a, in order
// If the number is in the upper side of the stack
// move up!
// if the top two numbers are the next two numbers to send to stack A
// use swap instead of rotate
// the number is in the lower side of the stack
// move down!

void	put_nb_on_top(t_stack **b, int nb, int next_nb, int check_next_nb)
{
	int	pos;

	pos = find_nb_pos(*b, nb);
	if (pos < (ft_lstsize(*b) / 2))
	{
		while ((*b)->value != nb)
		{
			if (check_next_nb && (*b)->next != NULL
				&& (*b)->next->value == nb && (*b)->value == next_nb)
				swap_b(b);
			else
				rotate_b(b);
		}
	}
	else
	{
		while ((*b)->value != nb)
			reverse_b(b);
	}
}

void	move_nb_back_to_stack_a(t_stack **a, t_stack **b, long long *array)
{
	int	i;
	int	len;
	int	nb;
	int	next_nb;
	int	check_next_nb;

	len = ft_lstsize(*b);
	i = 0;
	while (*b != NULL)
	{
		nb = array[len - i - 1];
		check_next_nb = 0;
		if (len - i - 2 >= 0)
		{
			next_nb = array[len - i - 2];
			check_next_nb = 1;
		}
		put_nb_on_top(b, nb, next_nb, check_next_nb);
		push_a(a, b);
		i++;
	}
}

long long	*clone_array(long long *arr)
{
	int			i;
	long long	*clone;

	i = 0;
	while (arr[i] != END)
		i++;
	clone = malloc(sizeof(long long) * (i + 1));
	if (clone == NULL)
		return (NULL);
	ft_memcpy(clone, arr, sizeof(long long) * (i + 1));
	return (clone);
}
