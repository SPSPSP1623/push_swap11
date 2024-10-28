/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: speladea <speladea@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-13 16:27:47 by speladea          #+#    #+#             */
/*   Updated: 2024-06-13 16:27:47 by speladea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa_min(unsigned long n)
{
	int		count;
	char	*hexa_min;

	count = 0;
	hexa_min = "0123456789abcdef";
	if (n > 15)
	{
		count += ft_hexa_min(n / 16);
		count += ft_hexa_min(n % 16);
	}
	else
		count += ft_print_c(hexa_min[n]);
	return (count);
}

int	ft_hexa_maj(unsigned long n)
{
	int		count;
	char	*hexa_maj;

	count = 0;
	hexa_maj = "0123456789ABCDEF";
	if (n > 15)
	{
		count += ft_hexa_maj(n / 16);
		count += ft_hexa_maj(n % 16);
	}
	else
		count += ft_print_c(hexa_maj[n]);
	return (count);
}

int	ft_print_x(unsigned int nb, const char format_id)
{
	int				count;
	unsigned long	n;

	count = 0;
	n = (unsigned long)nb;
	if (format_id == 'x')
		count += ft_hexa_min(n);
	if (format_id == 'X')
		count += ft_hexa_maj(n);
	return (count);
}
