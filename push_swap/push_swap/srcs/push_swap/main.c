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
	while (*s == ' ' || *s == '\t' || *s == '\n' || *s == '\r' || \
			*s == '\f' || *s == '\v')
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

static void	process_single_argument(char *syntax_test)
{
	int		n;
	int		i;
	int		seen_numbers[1000];
	int		seen_size;

	seen_size = 0;
	i = 0;
	while (syntax_test[i])
	{
		while (syntax_test[i] == ' ')
			i++;
		if (check_syntax_pre(&syntax_test[i]))
			free_and_print_error(NULL);
		n = ft_atol(&syntax_test[i]);
		if (check_int_range_pre(n))
			free_and_print_error(NULL);
		if (check_duplicate_pre(n, seen_numbers, seen_size))
			free_and_print_error(NULL);
		seen_numbers[seen_size] = n;
		seen_size++;
		while (syntax_test[i] != ' ' && syntax_test[i] != '\0')
			i++;
	}
}

static int	handle_empty_arguments(int argc, char **argv)
{
	if (argc == 1 || ((argc == 2) && (!argv[1][0] || argv[1][0] == ' ')))
	{
		if (argc == 2)
			ft_printf("Error\n");
		return (1);
	}
	return (0);
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
		if (n1 > n2)
			ft_printf("sa\n"); // Swap the two numbers
		return ;
	}
	n3 = ft_atol(numbers[2]);
	if (size == 3)
	{
		if (n1 > n2 && n1 > n3)
		{
			if (n2 > n3)
				ft_printf("sa\nra\n"); // sa: Swap top two, ra: Rotate
			else
				ft_printf("rra\n"); // rra: Reverse rotate
		}
		else if (n2 > n1 && n2 > n3)
		{
			if (n1 > n3)
				ft_printf("sa\n"); // sa: Swap top two
			else
				ft_printf("ra\n"); // ra: Rotate
		}
		else if (n3 > n1 && n3 > n2)
		{
			if (n1 > n2)
				ft_printf("sa\nra\n"); // sa: Swap top two, ra: Rotate
			else
				ft_printf("rra\n"); // rra: Reverse rotate
		}
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

int	main(int argc, char **argv)
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;

	if (handle_empty_arguments(argc, argv))
		return (1);
	if (argc == 2 && argv[1][0] != '\0')
	{
		process_single_argument(argv[1]);
		argv = split(argv[1], ' ');
		sort_numbers(argv);
	}
		init_stack_a(&stack_a, argv+1);

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

	if (argc == 2)
	{	
	free_split_result(argv);
	}
	return (0);
}
