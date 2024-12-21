/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrol-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 20:58:11 by jbrol-ca          #+#    #+#             */
/*   Updated: 2024/12/20 13:04:35 by jbrol-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static long	ft_atol(const char *s)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*s == ' ' || *s == '\t' || *s == '\n' || \
			*s == '\r' || *s == '\f' || *s == '\v')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while ((*s >= '0' && *s <= '9'))
	{
		result = result * 10 + (*s - '0');
		s++;
	}
	return (result * sign);
}

int	main(int argc, char **argv)
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;
	char			*syntax_test;
	int				n;
	int				i;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
	{
		if (argc == 2)
			ft_printf("Error\n");
		return (1);
	}
	if (argc == 2)
	{
		syntax_test = argv[1];
		i = 0;
		while (syntax_test[i] != '\0')
		{
			while (syntax_test[i] == ' ')
				i++;
			if (check_syntax(&syntax_test[i]))
				free_and_print_error(NULL);
			n = ft_atol(&syntax_test[i]);
			if (n > INT_MAX || n < INT_MIN)
				free_and_print_error(NULL);
			if (check_duplicate(stack_a, (int)n))
				free_and_print_error(NULL);
			while (syntax_test[i] != ' ' && syntax_test[i] != '\0')
				i++;
		}
		argv = split(argv[1], ' ');
	}
	init_stack_a(&stack_a, argv + 1);
	if (!stack_sorted(stack_a))
	{
		if (stack_len(stack_a) == 2)
			sa(&stack_a, false);
		else if (stack_len(stack_a) == 3)
			sort_three(&stack_a);
		else
			sort_stacks(&stack_a, &stack_b);
	}
	free_stack_memory(&stack_a);
	free_split_result(argv);
	return (0);
}
