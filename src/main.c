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

char	**arg_split(int argc, char **argv)
{
	char	*arg_join;
	char	*cache;
	char	**arg;
	int		i;

	i = 2;
	arg_join = ft_strdup(argv[1]);
	while (i < argc)
	{
		cache = arg_join;
		arg_join = ft_strjoin(cache, argv[i]);
		free(cache);
		i++;
	}
	arg = ft_split(arg_join, ' ');
	free(arg_join);
	return (arg);
}
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


void	print_stack(t_stack *stack)
{
	ft_printf("\n");
	while (stack)
	{
		ft_printf("%d", stack->value);
		if (stack->next != NULL)
			ft_printf("->");
		stack = stack->next;
	}
	ft_printf("\n");
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char 	**arguments;

	stack_a = NULL;
	stack_b = NULL;

	if (argc == 1)
		return (0);
	check_errors(argc, argv);
	arguments = arg_split(argc, argv);
	create_stack_a(&stack_a, arguments);
	ft_free_arguments(arguments);
	if (!not_dup(stack_a))
		error_handling(&stack_a, NULL);
	if (!is_stack_sorted(stack_a))
		push_swap(&stack_a, &stack_b);
	clear_stack(&stack_a);
	clear_stack(&stack_b);
}
