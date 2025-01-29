/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 08:59:39 by christophed       #+#    #+#             */
/*   Updated: 2025/01/29 18:52:43 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/push_swap.h"

// Function to shift all the elements of stack a up by one position
void	ra(t_stack **a)
{
	write(1, "ra\n", 3);
	if (!a || !*a || *a == (*a)->next)
		return ;
	*a = (*a)->next;
}

// Function to shift all the elements of stack b up by one position
void	rb(t_stack **b)
{
	write(1, "rb\n", 3);
	if (!b || !*b || *b == (*b)->next)
		return ;
	*b = (*b)->next;
}

// Function to shift all the elements of stack a up by one position
// and shift all the elements of stack b up by one position
void	rr(t_stack **a, t_stack **b)
{
	write(1, "rr\n", 3);
	if (a && *a)
		*a = (*a)->next;
	if (b && *b)
		*b = (*b)->next;
}
