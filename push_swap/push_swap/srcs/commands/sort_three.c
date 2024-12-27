/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrol-ca <jbrol-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:45:34 by jbrol-ca          #+#    #+#             */
/*   Updated: 2024/12/27 14:48:00 by jbrol-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	sort_three(t_stack_node **a)
{
	t_stack_node	*highest_value_node;

	highest_value_node = find_max(*a);
	if (highest_value_node == *a)
		ra(a, false);
	else if ((*a)->next == highest_value_node)
		rra(a, false);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a, false);
}

void	handle_two_numbers(int n1, int n2)
{
	if (n1 > n2)
		ft_printf("sa\n");
}

static void	handle_three_numbers(int n1, int n2, int n3)
{
	if (n1 > n2 && n1 > n3)
	{
		if (n2 > n3)
			ft_printf("sa\nra\n");
		else
			ft_printf("rra\n");
	}
	else if (n2 > n1 && n2 > n3)
	{
		if (n1 > n3)
			ft_printf("sa\n");
		else
			ft_printf("ra\n");
	}
	else if (n3 > n1 && n3 > n2)
	{
		if (n1 > n2)
			ft_printf("sa\nra\n");
		else
			ft_printf("rra\n");
	}
}

void	sort_numbers(char **numbers)
{
	int	n1;
	int	n2;
	int	n3;
	int	size;

	n1 = ft_atol(numbers[0]);
	n2 = ft_atol(numbers[1]);
	size = count_elements_in_array(numbers);
	if (size == 2)
	{
		handle_two_numbers(n1, n2);
		return ;
	}
	n3 = ft_atol(numbers[2]);
	if (size == 3)
	{
		handle_three_numbers(n1, n2, n3);
	}
}

int	count_elements_in_array(char **array)
{
	int	count;

	count = 0;
	while (array[count] != NULL)
	{
		count++;
	}
	return (count);
}
