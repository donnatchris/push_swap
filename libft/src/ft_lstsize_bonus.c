/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 08:51:21 by chdonnat          #+#    #+#             */
/*   Updated: 2024/12/16 17:31:25 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*lst_actual;

	lst_actual = lst;
	size = 0;
	while (lst_actual != NULL)
	{
		size++;
		lst_actual = lst_actual->next;
	}
	return (size);
}
