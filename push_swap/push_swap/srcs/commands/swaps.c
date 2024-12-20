/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrol-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:45:53 by jbrol-ca          #+#    #+#             */
/*   Updated: 2024/12/19 22:06:36 by jbrol-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	swap_nodes(t_stack_node **head)
{
	t_stack_node	*first;
	t_stack_node	*second;

	if (!*head || !(*head)->next)
		return ;
	first = *head;
	second = (*head)->next;
	*head = second;
	first->next = second->next;
	if (first->next)
		first->next->previous = first;
	second->previous = NULL;
	second->next = first;
	first->previous = second;
}

void	sa(t_stack_node **a, bool print)
{
	swap_nodes(a);
	if (!print)
		ft_printf("sa\n");
}

void	sb(t_stack_node **b, bool print)
{
	swap_nodes(b);
	if (!print)
		ft_printf("sb\n");
}

void	ss(t_stack_node **a, t_stack_node **b, bool print)
{
	swap_nodes(a);
	swap_nodes(b);
	if (!print)
		ft_printf("ss\n");
}
