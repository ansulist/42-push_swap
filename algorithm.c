/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansulist <ansulist@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 22:17:32 by ansulist          #+#    #+#             */
/*   Updated: 2023/04/10 14:20:44 by ansulist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_c_to_a(t_stack **a, t_stack **b, long long *array, int c_size)
{
	int	i;
	int	len;
	int	nb_chunks;

	len = ft_lstsize(*b);
	nb_chunks = get_nb_chunk(len, c_size);
	i = 0;
	while (i < nb_chunks)
	{
		c_to_stack_a(a, b, array + (i * c_size), c_size);
		i++;
	}
}

void	move_c_to_b(t_stack **a, t_stack **b, long long *array, int c_size)
{
	int	i;
	int	len;
	int	nb_chunks;

	len = ft_lstsize(*a);
	nb_chunks = get_nb_chunk(len, c_size);
	i = 0;
	while (i < nb_chunks)
	{
		c_to_stack_b(a, b, array + (i * c_size), c_size);
		i++;
	}
}

void	b_n_f(t_stack **a, t_stack **b, long long *array, long long *cpy)
{
	int	i;
	int	chunk_size;
	int	len;

	i = 0;
	chunk_size = 40;
	len = ft_lstsize(*b);
	while (i < 2)
	{
		ft_memcpy(cpy, array, sizeof(long long) * (len + 1));
		if (i == 0)
			move_c_to_a(a, b, cpy, chunk_size);
		else
			move_c_to_b(a, b, cpy, chunk_size);
		chunk_size /= 2;
		i++;
	}
}

// [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
// |--------------|---------------|
//    chunk 1         chunk 2
// Step 1: For one chunk at a time
// Looks for chunk's number in stackA and push them to stackB
// Order depends on how far numbers are
// (number of instructions required to move to B)
// Step 2: Move all numbers back to stack A, in order
int	fancy_algorithm(t_stack **a, t_stack **b, long long *array)
{
	int			len;
	int			chunk_size;
	long long	*cpy_array;

	len = ft_lstsize(*a);
	chunk_size = 20;
	if (len > 100)
		chunk_size = 80;
	cpy_array = clone_array(array);
	if (cpy_array == NULL)
		return (-1);
	move_c_to_b(a, b, cpy_array, chunk_size);
	if (len > 100)
		b_n_f(a, b, array, cpy_array);
	free(cpy_array);
	move_nb_back_to_stack_a(a, b, array);
	return (0);
}

int	sort_simple(t_stack **a, t_stack **b, long long *array)
{
	int	lstsize;

	lstsize = ft_lstsize(*a);
	if (lstsize <= 1 || sorted(*a) == 1)
		return (-1);
	if (lstsize == 2)
		sort_2(a);
	else if (lstsize == 3)
		sort_3(a);
	else if (lstsize == 4)
		sort_4(a, b);
	else if (lstsize == 5)
		sort_5(a, b);
	else
		return (fancy_algorithm(a, b, array));
	return (0);
}
