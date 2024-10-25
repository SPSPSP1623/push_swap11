/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: speladea <speladea@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-22 21:20:40 by speladea          #+#    #+#             */
/*   Updated: 2024-10-22 21:20:40 by speladea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	int	len;

	len = stack_len(*stack_a);
	give_index(*stack_a);
	if (len == 2)
		sa(stack_a);
	if (len == 3)
		sort_three(stack_a);
	if (len == 4)
		sort_four(stack_a, stack_b);
	if (len == 5)
		sort_five(stack_a, stack_b);
	if (len > 5)
		sort_more(stack_a, stack_b);
}

/*
void	print_stack(t_stack *stack)
{
	while (stack)
	{
		ft_printf("%d", stack->value);
		if (stack->next != NULL)
			ft_printf("->");
		stack = stack->next;
	}
	ft_printf("\n");
}
*/

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	else if (argc == 2)
	{
		if (!argv[1][0] || argv[1][0] == ' ')
			error_handling(NULL, NULL);
		else
			split_arg(argc, argv[1], &stack_a);
	}
	else
		create_stack_a(argc, &stack_a, argv);
	//print_stack(stack_a);
	if (!not_dup(stack_a))
		error_handling(&stack_a, NULL);
	if (!is_stack_sorted(stack_a))
		push_swap(&stack_a, &stack_b);
	//print_stack(stack_a);
	clear_stack(&stack_a);
	clear_stack(&stack_b);
}
