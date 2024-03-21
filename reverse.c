/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansulist <ansulist@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 00:21:42 by ansulist          #+#    #+#             */
/*   Updated: 2023/04/10 12:20:58 by ansulist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// first simpan node paling akhir yg ga berakhiran NULL
// lalu pindah alamat si a jadi ke node terakhir
// lalu ubah node kedua terakhir jadi NULL
// karna last node udah di pindah ke atas
void	reverse_a(t_stack **a)
{
	t_stack	*last;
	t_stack	*tmp;

	last = *a;
	tmp = *a;
	while (last->next != NULL)
	{
		tmp = last;
		last = last->next;
	}
	last->next = *a;
	*a = last;
	tmp->next = NULL;
	ft_putstr("rra\n");
}

void	reverse_b(t_stack **b)
{
	t_stack	*last;
	t_stack	*tmp;

	last = *b;
	tmp = *b;
	while (last->next != NULL)
	{
		tmp = last;
		last = last->next;
	}
	last->next = *b;
	*b = last;
	tmp->next = NULL;
	ft_putstr("rrb\n");
}

void	reverse_rrr(t_stack **a, t_stack **b)
{
	reverse_a(a);
	reverse_b(b);
	ft_putstr("rrr\n");
}
