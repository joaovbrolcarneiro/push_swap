/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_on_top.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrol-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:42:45 by jbrol-ca          #+#    #+#             */
/*   Updated: 2024/12/19 21:57:35 by jbrol-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	min_on_top(t_stack_node **stack_a)
{
	t_stack_node	*min_node;

	min_node = find_min(*stack_a);
	while ((*stack_a)->nbr != min_node->nbr)
	{
		if (min_node->above_median)
			ra(stack_a, false);
		else
			rra(stack_a, false);
	}
}
