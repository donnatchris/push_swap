/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexamin_pf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:12:20 by chdonnat          #+#    #+#             */
/*   Updated: 2024/12/16 18:17:47 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_puthexamin_pf(unsigned int n, int *count)
{
	char	*str;

	str = "0123456789abcdef";
	if (n > 15)
		ft_puthexamin_pf(n / 16, count);
	ft_putchar_pf(str[n % 16], count);
}
