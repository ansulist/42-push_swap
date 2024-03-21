/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansulist <ansulist@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 00:21:03 by ansulist          #+#    #+#             */
/*   Updated: 2023/04/10 14:23:35 by ansulist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Check that given sorted array only contains
// unique values
// The number is there twice
int	check_unique(long long *sorted_arr)
{
	int	i;
	int	previous;

	previous = sorted_arr[0];
	i = 1;
	while (sorted_arr[i] != END)
	{
		if (sorted_arr[i] == previous)
			return (-1);
		previous = sorted_arr[i];
		i++;
	}
	return (1);
}

int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-' || num[0] == '+')
		i++;
	while (num[i] != '\0')
	{
		if (ft_isdigit(num[i]) != 1)
			return (0);
		i++;
	}
	return (1);
}

int	check_numbers(char **args)
{
	long long	temp;
	int			i;

	i = 0;
	while (args[i] != NULL)
	{
		if (ft_isnum(args[i]) != 1)
		{
			free_array_2d(&args);
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		temp = ft_atoi(args[i]);
		if (temp < -2147483648 || temp > 2147483647)
		{
			free_array_2d(&args);
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_args(int ac, char **av)
{
	int		i;
	char	**args;

	if (ac <= 1)
		return (0);
	i = 1;
	while (av[i] != NULL)
	{
		args = ft_split(av[i], ' ');
		if (args == NULL)
			return (0);
		if (check_numbers(args) == 0)
			return (0);
		free_array_2d(&args);
		i++;
	}
	return (1);
}
