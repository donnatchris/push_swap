/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:06:01 by christophed       #+#    #+#             */
/*   Updated: 2024/12/17 22:04:26 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Function to find a node by its position in the doubly circular linked list
t_stack	*dclst_find_node(t_stack *head, int position)
{
	t_stack	*current;
	int		i;

	if (!head)
		return (NULL);
	current = head;
	i = 0;
	while (i < position)
	{
		current = current->next;
		i++;
	}
	return (current);
}

// Function to choose the pivot by selcting the median of the first, middle and last element
int	choose_pivot(t_stack *stack_a, int count)
{
	int		first;
	int		middle;
	int		last;

	first = stack_a->data;
	middle = dclst_find_node(stack_a, count / 2)->data;
	last = dclst_find_node(stack_a, count - 1)->data;
	if (first > middle)
	{
		if (middle > last)
			return (middle);
		else if (first > last)
			return (last);
		else
			return (first);
	}
	else
	{
		if (first > last)
			return (first);
		else if (middle > last)
			return (last);
		else
			return (middle);
	}
}

// Function to sort a stack with 3 elements
void	sort_3(t_stack **stack)
{
	printf("demi-liste: ");
	dclst_print(*stack);
	printf("sort_3\n");
	if ((*stack)->data < (*stack)->next->data && (*stack)->data < (*stack)->previous->data)
	{
		if ((*stack)->next->data > (*stack)->previous->data)
		{
			sa(stack);
			ra(stack);
		}
	}
	else if ((*stack)->data > (*stack)->next->data && (*stack)->data > (*stack)->previous->data)
	{
		ra(stack);
		if ((*stack)->data > (*stack)->next->data)
			sa(stack);
	}
	else
	{
		if ((*stack)->previous->data < (*stack)->data)
			rra(stack);
		else
			sa(stack);
	}
}

// Function to sort the stack_b recursively
int	sort_b_by_pivot(t_stack **stack_a, t_stack **stack_b, int count)
{
	int		pivot;
	int		pushed;
	int		i;

	printf("liste a :");
	dclst_print(*stack_a);
	printf("liste b :");
	dclst_print(*stack_b);
	printf("SORT B BY PIVOT\n");
	pushed = 0;
	if (count < 3)
	{
		printf("COUNT B <= 2\n");
		if ((*stack_b)->data > (*stack_b)->next->data)
			sb(stack_b);
	}
	if (count > 2)
	{
		pivot = choose_pivot(*stack_b, count);
		printf("COUNT B > 2 PIVOT: %d\n", pivot);
		i = 0;
		while (i < count)
		{
			if ((*stack_b)->data < pivot)
			{
				if (pa(stack_a, stack_b) < 0)
					return (-1);
				pushed++;
			}
			else
				if (i != count - 1)
					rb(stack_b);
			i++;
		}
		printf("PUSHED FROM B TO A: %d\n", pushed);
		if (sort_a_by_pivot(stack_a, stack_b, pushed) < 0)
			return (-1);
		i = 0;
		while (i < pushed)
		{
			if (sort_a_by_pivot(stack_a, stack_b, pushed) < 0)
				return (-1);
			printf("RETURN B TO A: PUSHED %d\n", pushed);
			if (pb(stack_a, stack_b) < 0)
				return (-1);
			i++;
		}
	}
	return (0);
}

// Function to sort the stack_a recursively
int	sort_a_by_pivot(t_stack **stack_a, t_stack **stack_b, int count)
{
	int		pivot;
	int		pushed;
	int		i;

	printf("liste a :");
	dclst_print(*stack_a);
	printf("liste b :");
	dclst_print(*stack_b);
	printf("SORT A BY PIVOT\n");
	pushed = 0;
	if (count < 3)
	{
		printf("COUNT A <= 2\n");
		if ((*stack_a)->data > (*stack_a)->next->data)
			sa(stack_a);
	}
	else
	{
		pivot = choose_pivot(*stack_a, count);
		printf("COUNT A > 2 PIVOT: %d\n", pivot);
		i = 0;
		while (i < count)
		{
			if ((*stack_a)->data < pivot)
			{
				if (pb(stack_a, stack_b) < 0)
					return (-1);
				pushed++;
			}
			else
				if(i != count - 1)
					ra(stack_a);
			i++;
		}
		printf("PUSHED FROM A TO B: %d\n", pushed);
		if (sort_b_by_pivot(stack_a, stack_b, pushed) < 0)
			return (-1);
		i = 0;
		while (i < pushed)
		{
			printf("RETURN A FROM B: PUSHED %d\n", pushed);
			if (pa(stack_a, stack_b) < 0)
				return (-1);
			i++;
		}
	}
	return (0);
}

// Function to sort the stack using a quicksort algorithm
int	quicksort(t_stack **stack_a, t_stack **stack_b)
{
	int		count;
	int		pivot;
	int		i;
	int		pushed_to_b;

	count = dclst_count_nodes(*stack_a);
	if (sort_a_by_pivot(stack_a, stack_b, count) < 0)
		return (-1);
	return (0);
}