/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansulist <ansulist@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 00:21:52 by ansulist          #+#    #+#             */
/*   Updated: 2023/04/10 12:21:19 by ansulist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stack *stack)
{
	int		min_value;
	t_stack	*min;

	min = stack;
	min_value = min->value;
	while (min != NULL)
	{
		if (min->value < min_value)
			min_value = min->value;
		min = min->next;
	}
	return (min_value);
}

void	sort_2(t_stack **a)
{
	if ((*a)->value > (*a)->next->value)
		swap_a(a);
}

void	sort_3(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (sorted(*a) == 1)
		return ;
	if (first > second && first > third && second > third)
	{
		swap_a(a);
		return (reverse_a(a));
	}
	if (first > second && first > third && third > second)
		return (rotate_a(a));
	if (first > second && first < third)
		return (swap_a(a));
	if (first < second && first > third)
		return (reverse_a(a));
	reverse_a(a);
	swap_a(a);
}

void	sort_4(t_stack **a, t_stack **b)
{
	int	location;

	location = ft_locate(*a, find_min(*a));
	if (location == 1)
		rotate_a(a);
	if (location == 2)
	{
		rotate_a(a);
		rotate_a(a);
	}
	if (location == 3)
		reverse_a(a);
	if (sorted(*a) == 1)
		return ;
	push_b(a, b);
	sort_3(a);
	push_a(a, b);
}

void	sort_5(t_stack **a, t_stack **b)
{
	int	location;

	location = ft_locate(*a, find_min(*a));
	if (location == 1)
		rotate_a(a);
	if (location == 2)
	{
		rotate_a(a);
		rotate_a(a);
	}
	if (location == 3)
	{
		reverse_a(a);
		reverse_a(a);
	}
	if (location == 4)
		reverse_a(a);
	if (sorted(*a) == 1)
		return ;
	push_b(a, b);
	sort_4(a, b);
	push_a(a, b);
}
