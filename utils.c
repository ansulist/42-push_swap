/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansulist <ansulist@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 00:22:10 by ansulist          #+#    #+#             */
/*   Updated: 2023/04/10 12:12:42 by ansulist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_array_2d(char ***str)
{
	int	i;

	i = 0;
	while ((*str)[i] != NULL)
	{
		free((*str)[i]);
		i++;
	}
	free(*str);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_locate(t_stack *stack, int index)
{
	t_stack	*temp;
	int		pos;

	pos = 0;
	temp = stack;
	while (temp->next != NULL)
	{
		if (temp->value == index)
			return (pos);
		temp = temp->next;
		pos++;
	}
	return (pos);
}

int	sorted(t_stack *stack)
{
	t_stack	*head;

	head = stack;
	while (head && head->next)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}

int	find_max(t_stack *stack)
{
	int		max_value;
	t_stack	*max;

	max = stack;
	max_value = max->value;
	while (max->next != NULL)
	{
		if (max->value > max_value)
			max_value = max->value;
		max = max->next;
	}
	return (max_value);
}
