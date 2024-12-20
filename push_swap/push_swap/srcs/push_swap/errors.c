/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrol-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 12:00:00 by jbrol-ca          #+#    #+#             */
/*   Updated: 2024/12/20 12:44:36 by jbrol-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	check_syntax(char *str)
{
	if (!(*str == '+' || *str == '-' || (*str >= '0' && *str <= '9')))
		return (1);
	if ((*str == '+' || *str == '-') && !(str[1] >= '0' && str[1] <= '9'))
		return (1);
	while (*++str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (1);
	}
	return (0);
}

int	check_duplicate(t_stack_node *stack, int value)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->nbr == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	free_stack_memory(t_stack_node **stack)
{
	t_stack_node	*next_node;
	t_stack_node	*current_node;

	if (!stack)
		return ;
	current_node = *stack;
	while (current_node)
	{
		next_node = current_node->next;
		current_node->nbr = 0;
		free(current_node);
		current_node = next_node;
	}
	*stack = NULL;
}

void	free_and_print_error(t_stack_node **stack)
{
	free_stack_memory(stack);
	ft_printf("Error\n");
	exit(1);
}