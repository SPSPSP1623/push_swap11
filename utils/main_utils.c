/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: speladea <speladea@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-22 19:39:05 by speladea          #+#    #+#             */
/*   Updated: 2024-10-22 19:39:05 by speladea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*new_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->next = NULL;
	return (node);
}

t_stack	*stack_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

void	add_back_stack(t_stack **stack, t_stack *node)
{
	t_stack	*last;

	if (!*stack || !node)
		return ;
	last = stack_last(*stack);
	last->next = node;
}

void	create_stack_a(int argc, t_stack **stack_a, char *argv[])
{
	int		i;
	long	nbr;

	if (argc == 2)
		i = 0;
	if (argc >= 3)
		i = 1;
	nbr = 0;
	while (argv[i])
	{
		if (!not_int(argv[i]))
			error_handling(stack_a, NULL);
		nbr = ft_atol(argv[i]);
		if (nbr < INT_MIN || nbr > INT_MAX)
			error_handling(stack_a, NULL);
		if ((i == 0 && argc == 2) || (i == 1 && argc >= 3))
		{
			if (!(*stack_a = new_node(nbr)))
				error_handling(stack_a, NULL);
		}
		else
			add_back_stack(stack_a, new_node(nbr));
		i++;
	}
}

void	split_arg(int argc, char *argv, t_stack **stack_a)
{
	char	**arg_splitted;
	int	i;

	arg_splitted = ft_split(argv, ' ');
	if (!arg_splitted)
		error_handling(NULL, NULL);
	create_stack_a(argc, stack_a, arg_splitted);
	i = 0;
	while (arg_splitted[i])
	{
		free(arg_splitted[i]);
		i++;
	}
	free(arg_splitted);
}