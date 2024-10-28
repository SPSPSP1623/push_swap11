/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: speladea <speladea@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-13 16:25:49 by speladea          #+#    #+#             */
/*   Updated: 2024-06-13 16:25:49 by speladea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_u(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb >= 10)
		count += ft_print_u(nb / 10);
	count += ft_print_c(nb % 10 + '0');
	return (count);
}
