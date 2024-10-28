/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: speladea <speladea@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-22 19:53:37 by speladea          #+#    #+#             */
/*   Updated: 2024-10-22 19:53:37 by speladea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	w_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	error_handling(t_stack **stack_a, t_stack **stack_b)
{
	clear_stack(stack_a);
	clear_stack(stack_b);
	w_error();
}

void	check_errors(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		if (!argv[i][0] || (argv[i][0] == ' ' && argv[i][1] == '\0'))
			error_handling(NULL, NULL);
		i++;
	}
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] != ' ')
				return ;
			j++;
		}
		i++;
	}
	error_handling(NULL, NULL);
}

int	not_int(char *argv)
{
	int	i;

	i = 0;
	if (!(argv[i] == '-' || argv[i] == '+' || (argv[i] >= '0' \
		&& argv[i] <= '9')))
		return (0);
	if ((argv[i] == '-' || argv[i] == '+') && !(argv[1] >= '0' \
		&& argv[1] <= '9'))
		return (0);
	if (argv[i] == '-' || argv[i] == '+')
		i++;
	while (argv[i])
	{
		if (!(argv[i] >= '0' && argv[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	not_dup(t_stack *stack_a)
{
	t_stack	*tmp;

	tmp = stack_a;
	while (stack_a->next != NULL)
	{
		tmp = stack_a->next;
		while (tmp)
		{
			if (stack_a->value == tmp->value)
				return (0);
			tmp = tmp->next;
		}
		stack_a = stack_a->next;
	}
	return (1);
}
