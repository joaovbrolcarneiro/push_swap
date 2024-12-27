/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrol-ca <jbrol-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 20:58:11 by jbrol-ca          #+#    #+#             */
/*   Updated: 2024/12/27 16:19:51 by jbrol-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	check_syntax_pre(char *str)
{
	int	i;
	int	sign_found;

	i = 0;
	sign_found = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			i++;
		else if (str[i] == '+' || str[i] == '-')
		{
			if (i > 0 && str[i - 1] != ' ' || sign_found)
				return (1);
			sign_found = 1;
			i++;
			if (!(str[i] >= '0' && str[i] <= '9'))
				return (1);
		}
		else if (str[i] >= '0' && str[i] <= '9')
			while (str[i] >= '0' && str[i] <= '9')
				i++;
		else
			return (1);
	}
	return (0);
}

int	check_int_range_pre(long n)
{
	if (n > INT_MAX || n < INT_MIN)
		return (1);
	return (0);
}

int	check_dup_pre(int value, int *seen_numbers, int seen_size)
{
	int	i;

	i = 0;
	while (i < seen_size)
	{
		if (seen_numbers[i] == value)
			return (1);
		i++;
	}
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
