/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansulist <ansulist@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 00:21:33 by ansulist          #+#    #+#             */
/*   Updated: 2023/04/10 14:20:52 by ansulist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include "./libft/libft.h"

// Flags
# define END 4000000000
# define DONE 5000000000
# define DISPLAY_OPS 1

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

//algorithm
void		move_c_to_a(t_stack **a, t_stack **b, long long *array, int c_size);
void		move_c_to_b(t_stack **a, t_stack **b, long long *array, int c_size);
void		b_n_f(t_stack **a, t_stack **b, long long *array, long long *cpy);
int			fancy_algorithm(t_stack **a, t_stack **b, long long *array);
int			sort_simple(t_stack **a, t_stack **b, long long *array);
int			get_nb_chunk(int len, int chunk_size);
void		move_number_to_stack_a(t_stack **a, t_stack **b, int nb);
void		move_number_to_stack_b(t_stack **a, t_stack **b, int nb);
int			nb_op_to_stack_b(t_stack *a, int nb);
int			give_nb_index(t_stack **a, long long *array, int len);
void		c_to_stack_a(t_stack **a, t_stack **b, long long *array, int len);
void		c_to_stack_b(t_stack **a, t_stack **b, long long *array, int len);
void		put_nb_on_top(t_stack **b, int nb, int next_nb, int check_next_nb);
void		move_nb_back_to_stack_a(t_stack **a, t_stack **b, long long *array);
long long	*clone_array(long long *arr);
int			find_min(t_stack *stack);
void		sort_2(t_stack **a);
void		sort_3(t_stack **a);
void		sort_4(t_stack **a, t_stack **b);
void		sort_5(t_stack **a, t_stack **b);
long long	*list_to_tab(t_stack **stack);
void		ft_sort_long_long_tab(long long *tab);
int			find_nb_pos(t_stack *a, int nb);

//list functions
void		ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack		*ft_lstlast(t_stack *lst);
t_stack		*ft_lstnew(int content);
void		lst_free(t_stack *stack);
int			ft_lstsize(t_stack *lst);

//main
int			split_and_push(t_stack **stack, char *to_split);
t_stack		*parsing(int argc, char **argv);
int			init_stacks(int ac, char **av, t_stack **a, t_stack **b);
int			init_array(long long **array, t_stack **a);
int			main(int ac, char **av);

//checks
int			check_unique(long long *sorted_arr);
int			ft_isnum(char *num);
int			check_numbers(char **args);
int			check_args(int ac, char **av);

//moves
void		push_a(t_stack **a, t_stack **b);
void		push_b(t_stack **a, t_stack **b);
void		reverse_a(t_stack **a);
void		reverse_b(t_stack **b);
void		reverse_rrr(t_stack **a, t_stack **b);
void		rotate_a(t_stack **a);
void		rotate_b(t_stack **b);
void		rotate_rr(t_stack **a, t_stack **b);
void		swap_a(t_stack **a);
void		swap_b(t_stack **b);
void		swap_ss(t_stack **a, t_stack **b);

//utils
void		free_array_2d(char ***str);
void		ft_putstr(char *str);
int			ft_locate(t_stack *stack, int index);
int			sorted(t_stack *stack);
int			find_max(t_stack *stack);

#endif