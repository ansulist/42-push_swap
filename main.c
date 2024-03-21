/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansulist <ansulist@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 00:21:16 by ansulist          #+#    #+#             */
/*   Updated: 2023/04/10 14:23:50 by ansulist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	split_and_push(t_stack **stack, char *to_split)
{
	char	**splitted;
	int		j;

	splitted = ft_split(to_split, ' ');
	if (splitted == NULL)
		return (-1);
	j = 0;
	while (splitted[j] != NULL)
	{
		ft_lstadd_back(stack, ft_lstnew(ft_atoi(splitted[j])));
		j++;
	}
	free_array_2d(&splitted);
	return (0);
}

t_stack	*parsing(int argc, char **argv)
{
	t_stack	*stack;
	int		i;

	i = 1;
	stack = NULL;
	if (argc <= 1)
		return (NULL);
	while (argv[i] != NULL)
	{
		if (split_and_push(&stack, argv[i]) == -1)
		{
			lst_free(stack);
			return (NULL);
		}
		i++;
	}
	return (stack);
}

int	init_stacks(int ac, char **av, t_stack **a, t_stack **b)
{
	*b = NULL;
	*a = parsing(ac, av);
	if (*a == NULL)
		return (-1);
	return (1);
}

int	init_array(long long **array, t_stack **a)
{
	*array = list_to_tab(a);
	if (*array == NULL)
		return (-1);
	ft_sort_long_long_tab(*array);
	return (check_unique(*array));
}

int	main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;
	long long	*array;
	int			ret;

	array = NULL;
	if (ac < 2 || check_args(ac, av) == 0)
		return (-1);
	if (init_stacks(ac, av, &a, &b) == -1 || init_array(&array, &a) == -1)
	{
		ft_putstr_fd("Error\n", 2);
		ret = -1;
	}
	else
	{
		if (sorted(a) == 1)
			ret = 1;
		else
			ret = sort_simple(&a, &b, array);
	}
	free(array);
	lst_free(a);
	lst_free(b);
	return (ret);
}
