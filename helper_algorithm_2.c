/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_algorithm_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansulist <ansulist@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 11:39:26 by ansulist          #+#    #+#             */
/*   Updated: 2023/04/07 13:11:55 by ansulist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	back_to_stack_a(t_stack **a, t_stack **b, long long *array)
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

int	get_nb_chunk(int len, int chunk_size)
{
	int	nb_chunks;

	nb_chunks = len / chunk_size;
	if (len % chunk_size > 0)
		nb_chunks++;
	return (nb_chunks);
}

void	chunks_to_b(t_stack **a, t_stack **b, long long *array, int c_size)
{
	int	i;
	int	len;
	int	nb_chunks;

	len = ft_lstsize(*a);
	nb_chunks = get_nb_chunk(len, c_size);
	i = 0;
	while (i < nb_chunks)
	{
		to_stack_b(a, b, array + (i * c_size), c_size);
		i++;
	}
}
