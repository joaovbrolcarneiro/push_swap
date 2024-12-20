/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrol-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:45:45 by jbrol-ca          #+#    #+#             */
/*   Updated: 2024/12/19 22:04:27 by jbrol-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	rotate_both(t_stack_node **stack_a, t_stack_node **stack_b,
						t_stack_node *min_node)
{
	while (*stack_b != min_node->target_node && *stack_a != min_node)
	{
		rr(stack_a, stack_b, false);
	}
	current_index(*stack_a);
	current_index(*stack_b);
}

static void	rev_rotate_both(t_stack_node **stack_a, t_stack_node **stack_b,
								t_stack_node *min_node)
{
	while (*stack_b != min_node->target_node && *stack_a != min_node)
	{
		rrr(stack_a, stack_b, false);
	}
	current_index(*stack_a);
	current_index(*stack_b);
}

static void	move_a_to_b(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*min_node;

	min_node = get_cheapest(*stack_a);
	if (min_node->above_median && min_node->target_node->above_median)
	{
		rotate_both(stack_a, stack_b, min_node);
	}
	while (*stack_b != min_node->target_node
		&& *stack_a != min_node)
	{
		rev_rotate_both(stack_a, stack_b, min_node);
	}
	prep_for_push(stack_a, min_node, 'a');
	prep_for_push(stack_b, min_node->target_node, 'b');
	pb(stack_b, stack_a, false);
}

static void	move_b_to_a(t_stack_node **stack_a, t_stack_node **stack_b)
{
	prep_for_push(stack_a, (*stack_b)->target_node, 'a');
	pa(stack_a, stack_b, false);
}

void	sort_stacks(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	stack_a_len;

	stack_a_len = stack_len(*stack_a);
	if (stack_a_len-- > 3 && !stack_sorted(*stack_a))
		pb(stack_b, stack_a, false);
	if (stack_a_len-- > 3 && !stack_sorted(*stack_a))
		pb(stack_b, stack_a, false);
	while (stack_a_len-- > 3 && !stack_sorted(*stack_a))
	{
		init_nodes_a(*stack_a, *stack_b);
		move_a_to_b(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		init_nodes_b(*stack_a, *stack_b);
		move_b_to_a(stack_a, stack_b);
	}
	current_index(*stack_a);
	min_on_top(stack_a);
}
