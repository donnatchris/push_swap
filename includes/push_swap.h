/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 09:00:06 by christophed       #+#    #+#             */
/*   Updated: 2024/12/27 11:17:09 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// Libraries
# include <unistd.h>
# include <stdlib.h>

// Structure for the doubly circular linked list
typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
	struct s_stack	*previous;
}					t_stack;

// SRC DIRECTORY
// src/main.c
t_stack	*dclst_load(char **args);
void	clear_all(t_stack **a, t_stack **b, char **args, int ac);
int		main(int ac, char **av);
// src/swap_functions.c
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
// src/push_functions.c
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
// src/reverse_rotate_functions.c
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
// src/rotate_functions.c
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
// src/recursive_sort_1.c
int		pivot_value(t_stack *head, int len);
void	sort_pushed_b(t_stack **a, t_stack **b, int len);
void	sort_pushed_a(t_stack **a, t_stack **b, int len);
void	recursive_sort(t_stack **a, t_stack **b, int len);
void	push_swap(t_stack **a, t_stack **b);
// src/recursive_sort_2.c
void	get_back_to_a(t_stack **a, t_stack **b, int len);
void	get_back_to_b(t_stack **a, t_stack **b, int len);
int		first_divide_a_by_treshold(
			t_stack **a, t_stack **b, int len, int treshold);
int		divide_a_by_treshold(t_stack **a, t_stack **b, int len, int treshold);
int		divide_b_by_treshold(t_stack **a, t_stack **b, int len, int treshold);

// src/sort_utils.c
int		is_sorted(t_stack *stack, int len);
int		is_reverse_sorted(t_stack *stack, int len);
void	sort_2a(t_stack **a);
void	sort_2b(t_stack **b);
void	sort_3(t_stack **a);

// UTILS DIRECTORY
// utils/dclst1.c
t_stack	*dclst_create_node(int data);
t_stack	*dclst_insert_node_end(t_stack **head, int data);
t_stack	*dclst_insert_node_start(t_stack **head, int data);
void	dclst_remove_node(t_stack **head, t_stack *node);
void	dclst_clear(t_stack **head);
// utils/dclst2.c
void	dclst_print(t_stack *head);
t_stack	*dclst_find_min(t_stack *head);
t_stack	*dclst_find_max(t_stack *head);
int		dclst_find_node_pos(t_stack *head, t_stack *node);
t_stack	*dclst_find_node_with_pos(t_stack *head, int pos);
// utils/dclst3.c
int		dclst_count_nodes(t_stack *head);
int		dclst_swap_nodes(t_stack **head, t_stack *node1, t_stack *node2);
// utils/dclst4.c
void	dclst_move_node(t_stack **origin, t_stack **destination, t_stack *node);
// src/error_manager.c
int		check_input(char **args);
int		is_int(long n);
int		has_double(t_stack *head, int data);
// utils/ft_atoi_long.c
long	ft_atoi_long(const char *nptr);

#endif