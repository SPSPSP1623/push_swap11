/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: speladea <speladea@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-22 20:26:30 by speladea          #+#    #+#             */
/*   Updated: 2024-10-22 20:26:30 by speladea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	stack_len(t_stack *stack)
{
	int	len;

	len = 0;
	while (stack)
	{
		stack = stack->next;
		len++;
	}
	return (len);
}

int	is_stack_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value < stack->next->value)
			stack = stack->next;
		else
			return (0);
	}
	return (1);

}

t_stack	*min_number_index(t_stack *stack_a)
{
	t_stack	*stack;
	t_stack	*min;

	stack = stack_a;
	min = NULL;
	while (stack)
	{
		if (stack->index == -1 && (!min || stack->value < min->value))
			min = stack;
		stack = stack->next;
	}
	return (min);
}

void	give_index(t_stack *stack_a)
{
	int		index;
	t_stack	*stack_index;

	index = 0;
	stack_index = min_number_index(stack_a);
	while (stack_index)
	{
		stack_index->index = index;
		index++;
		stack_index = min_number_index(stack_a);
	}
}

void	clear_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack)
		return ;
	tmp = (*stack);
	while (tmp)
	{
		(*stack) = (*stack)->next;
		free(tmp);
		tmp = (*stack);
	}
	*stack = NULL;
}
