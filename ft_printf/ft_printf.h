/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: speladea <speladea@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-13 16:11:54 by speladea          #+#    #+#             */
/*   Updated: 2024-06-13 16:11:54 by speladea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *s, ...);
int	ft_format_id(const char format_id, va_list args);
int	ft_print_c(char c);
int	ft_print_s(char *s);
int	ft_print_p(void *arg);
int	ft_print_di(int nb);
int	ft_print_u(unsigned int nb);
int	ft_print_x(unsigned int nb, const char format_id);

#endif
