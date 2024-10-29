/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: speladea <speladea@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-22 18:02:52 by speladea          #+#    #+#             */
/*   Updated: 2024-10-22 18:02:52 by speladea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft.h"
# include "ft_printf.h"
typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}				t_stack;

// OPERATIONS

// PUSH
void	push(t_stack **src, t_stack **dest);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
// REVERSE ROTATE
void	reverse_rotate(t_stack **stack);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
// ROTATE
void	rotate(t_stack **stack);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
// SWAP
void	swap(t_stack **stack);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);

// SORT
void	sort_three(t_stack **stack_a);
void	sort_four(t_stack **stack_a, t_stack **stack_b);
void	sort_five(t_stack **stack_a, t_stack **stack_b);
void	sort_more(t_stack **stack_a, t_stack **stack_b, int len);

// UTILS

// ERRORS
void	w_error(void);
void	error_handling(t_stack **stack_a, t_stack **stack_b);
void	check_errors(int argc, char *argv[]);
int		not_int(char *argv);
int		not_dup(t_stack *stack_a);
// MAIN_UTILS
t_stack	*new_node(int value);
t_stack	*stack_last(t_stack *stack);
void	add_back_stack(t_stack **stack, t_stack *node);
void	create_stack_a(t_stack **stack_a, char **arguments);
void	split_arg(int argc, char *argv, t_stack **stack_a);
// SORT_UTILS
int		get_min_index(t_stack *stack);
int		get_max_index(t_stack *stack);
int		max_bits(t_stack *stack);
void	ft_free_arguments(char **arguments);
// STACK_UTILS
int		stack_len(t_stack *stack);
int		is_stack_sorted(t_stack *stack);
t_stack	*min_number_index(t_stack *stack_a);
void	give_index(t_stack *stack_a);
void	clear_stack(t_stack **stack);

#endif
