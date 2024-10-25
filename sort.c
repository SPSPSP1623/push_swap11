/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: speladea <speladea@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-22 20:32:49 by speladea          #+#    #+#             */
/*   Updated: 2024-10-22 20:32:49 by speladea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack_a)
{
	int	max_index;

	max_index = get_max_index(*stack_a);
	if ((*stack_a)->index == max_index)
		ra(stack_a);
	else if ((*stack_a)->next->index == max_index)
		rra(stack_a);
	if ((*stack_a)->index > (*stack_a)->next->index)
		sa(stack_a);
}

void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	int	min_index;
	int	first_is_min;

	min_index = get_min_index(*stack_a);
	first_is_min = 0;
	while (first_is_min == 0)
	{
		if ((*stack_a)->index == min_index)
			first_is_min++;
		else
			rra(stack_a);
	}
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a)->next->index == 0)
		sa(stack_a);
	else if ((*stack_a)->next->next->index == 0)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if ((*stack_a)->next->next->next->index == 0)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if ((*stack_a)->next->next->next->next->index == 0)
		rra(stack_a);
	pb(stack_a, stack_b);
	sort_four(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort_more(t_stack **stack_a, t_stack **stack_b)
{
	int	len;
	int	max_b;
	int	i;
	int	j;

	len = stack_len(*stack_a);
	max_b = max_bits(*stack_a);
	i = 0;
	while (i < max_b)
	{
		j = 0;
		while (j < len)
		{
			if (((*stack_a)->index >> i) & 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			j++;
		}
		while (stack_len(*stack_b) != 0)
			pa(stack_a, stack_b);
		i++;
	}
}
