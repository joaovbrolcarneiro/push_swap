/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_to_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrol-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 20:58:11 by jbrol-ca          #+#    #+#             */
/*   Updated: 2024/12/20 13:17:32 by jbrol-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	current_index(t_stack_node *stack)
{
	int	index;
	int	median_pos;

	index = 0;
	if (!stack)
		return ;
	median_pos = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = index;
		if (index <= median_pos)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		++index;
	}
}

static void	set_target_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_b_node;
	t_stack_node	*target_node;
	long			closest_match;

	while (a)
	{
		closest_match = LONG_MIN;
		current_b_node = b;
		while (current_b_node)
		{
			if (current_b_node->nbr < a->nbr
				&& current_b_node->nbr > closest_match)
			{
				closest_match = current_b_node->nbr;
				target_node = current_b_node;
			}
			current_b_node = current_b_node->next;
		}
		if (closest_match == LONG_MIN)
			a->target_node = find_max(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

static void	cost_analysis_a(t_stack_node *a, t_stack_node *b)
{
	int	stack_a_len;
	int	stack_b_len;

	stack_a_len = stack_len(a);
	stack_b_len = stack_len(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->above_median))
			a->push_cost = stack_a_len - (a->index);
		if (a->target_node->above_median)
			a->push_cost += a->target_node->index;
		else
			a->push_cost += stack_b_len - (a->target_node->index);
		a = a->next;
	}
}

void	set_cheapest(t_stack_node *stack)
{
	long			min_cost;
	t_stack_node	*cheapest_node;

	if (!stack)
		return ;
	min_cost = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < min_cost)
		{
			min_cost = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	init_nodes_a(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);
}
