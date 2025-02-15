/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 08:59:59 by christophed       #+#    #+#             */
/*   Updated: 2024/12/28 10:30:36 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/push_swap.h"

// Main function to sort the stack_a
int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	**args;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (0);
	else if (ac == 2)
		args = ft_split(av[1], ' ');
	else
		args = av + 1;
	if (check_input(args) == -1)
		return (clear_all(&a, &b, args, ac), write(2, "Error\n", 6), 2);
	a = dclst_load(args);
	if (a == NULL)
		return (clear_all(&a, &b, args, ac), write(2, "Error\n", 6), 2);
	push_swap(&a, &b);
	if (!is_sorted(a, dclst_count_nodes(a)) || b)
		write(1, "Sort has failed\n", 16);
	clear_all(&a, &b, args, ac);
	return (0);
}
