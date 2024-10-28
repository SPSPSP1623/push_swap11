/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: speladea <speladea@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-13 16:18:28 by speladea          #+#    #+#             */
/*   Updated: 2024-06-13 16:18:28 by speladea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_s(char *s)
{
	int	count;
	int	i;

	if (!s)
		return (write(1, "(null)", 6));
	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		count += ft_print_c(s[i]);
		i++;
	}
	return (count);
}
