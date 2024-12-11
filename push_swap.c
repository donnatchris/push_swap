/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:20:08 by chdonnat          #+#    #+#             */
/*   Updated: 2024/12/11 17:28:58 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	if (ac < 2)
		return (0);
	if (check_input(av, ac) == -1)
		return (write(2, "Error\n", 6), 2);
	if (ac < 2)
		return (0)
}
