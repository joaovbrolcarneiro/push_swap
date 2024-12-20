/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrol-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:00:00 by jbrol-ca          #+#    #+#             */
/*   Updated: 2024/12/20 12:49:10 by jbrol-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	stack_len(t_stack_node *stack)
{
	int	total_nodes;

	if (!stack)
		return (0);
	total_nodes = 0;
	while (stack)
	{
		stack = stack->next;
		total_nodes++;
	}
	return (total_nodes);
}

t_stack_node	*find_last(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

bool	stack_sorted(t_stack_node *stack)
{
	if (!stack)
		return (true);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}

t_stack_node	*find_min(t_stack_node *stack)
{
	long			min_value;
	t_stack_node	*smallest_node;

	if (!stack)
		return (NULL);
	min_value = LONG_MAX;
	while (stack)
	{
		if (stack->nbr < min_value)
		{
			min_value = stack->nbr;
			smallest_node = stack;
		}
		stack = stack->next;
	}
	return (smallest_node);
}

t_stack_node	*find_max(t_stack_node *stack)
{
	long			max_value;
	t_stack_node	*largest_node;

	if (!stack)
		return (NULL);
	max_value = LONG_MIN;
	while (stack)
	{
		if (stack->nbr > max_value)
		{
			max_value = stack->nbr;
			largest_node = stack;
		}
		stack = stack->next;
	}
	return (largest_node);
}
