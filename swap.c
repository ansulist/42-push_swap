/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansulist <ansulist@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 00:22:04 by ansulist          #+#    #+#             */
/*   Updated: 2023/04/10 12:21:28 by ansulist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack **a)
{
	int	tmp;

	tmp = (*a)->value;
	(*a)->value = (*a)->next->value;
	(*a)->next->value = tmp;
	ft_putstr("sa\n");
}

void	swap_b(t_stack **b)
{
	int	tmp;

	tmp = (*b)->value;
	(*b)->value = (*b)->next->value;
	(*b)->next->value = tmp;
	ft_putstr("sb\n");
}

void	swap_ss(t_stack **a, t_stack **b)
{
	swap_a(a);
	swap_b(b);
	ft_putstr("ss\n");
}
