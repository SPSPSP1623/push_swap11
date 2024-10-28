/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: speladea <speladea@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-13 16:23:15 by speladea          #+#    #+#             */
/*   Updated: 2024-06-13 16:23:15 by speladea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_di(int nb)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		count = 11;
	}
	else if (nb < 0)
	{
		count += ft_print_c('-');
		count += ft_print_di(-nb);
	}
	else if (nb >= 10)
	{
		count += ft_print_di(nb / 10);
		count += ft_print_di(nb % 10);
	}
	else
		count += ft_print_c(nb + '0');
	return (count);
}
