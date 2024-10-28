/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: speladea <speladea@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-22 20:43:50 by speladea          #+#    #+#             */
/*   Updated: 2024-10-22 20:43:50 by speladea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_index(t_stack *stack)
{
	int	min_index;

	min_index = stack->index;
	while (stack)
	{
		if (stack->index < min_index)
			min_index = stack->index;
		stack = stack->next;
	}
	return (min_index);
}

int	get_max_index(t_stack *stack)
{
	int	max_index;

	max_index = stack->index;
	while (stack)
	{
		if (stack->index > max_index)
			max_index = stack->index;
		stack = stack->next;
	}
	return (max_index);
}

int	max_bits(t_stack *stack)
{
	int	max_index;
	int	max_b;

	max_index = get_max_index(stack);
	max_b = 0;
	while ((max_index >> max_b) != 0)
		max_b++;
	return (max_b);
}

void	ft_free_arguments(char **arguments)
{
	int	i;

	i = 0;
	while (arguments[i])
	{
		free(arguments[i]);
		i++;
	}
	free(arguments);
}
