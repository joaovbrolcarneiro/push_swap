/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrol-ca <jbrol-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 20:58:11 by jbrol-ca          #+#    #+#             */
/*   Updated: 2024/12/27 16:16:06 by jbrol-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static int	count_words(char *str, char delim)
{
	int	word_count;
	int	in_word;

	word_count = 0;
	in_word = 0;
	while (*str)
	{
		if (*str == delim)
			in_word = 0;
		else if (!in_word)
		{
			in_word = 1;
			word_count++;
		}
		str++;
	}
	return (word_count);
}

static char	*get_next_word(char **str_ptr, char delim)
{
	char	*start;
	char	*word;
	int		length;
	int		i;

	length = 0;
	while (**str_ptr && **str_ptr == delim)
		(*str_ptr)++;
	start = *str_ptr;
	while ((*str_ptr)[length] && (*str_ptr)[length] != delim)
		length++;
	word = malloc((length + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (i < length)
	{
		word[i] = start[i];
		i++;
	}
	word[length] = '\0';
	*str_ptr += length;
	return (word);
}

static char	**allocate_result_array(int words_count)
{
	char	**result_array;

	result_array = malloc((words_count + 2) * sizeof(char *));
	if (!result_array)
		return (NULL);
	result_array[0] = malloc(1);
	if (!result_array[0])
	{
		free(result_array);
		return (NULL);
	}
	result_array[0][0] = '\0';
	return (result_array);
}

char	**split(char *s, char c)
{
	int		words_count;
	char	**result_array;
	char	*str_ptr;
	int		i;

	if (!s)
		return (NULL);
	words_count = count_words(s, c);
	result_array = allocate_result_array(words_count);
	if (!result_array)
		return (NULL);
	str_ptr = s;
	i = 1;
	while (i <= words_count)
	{
		result_array[i] = get_next_word(&str_ptr, c);
		if (!result_array[i])
		{
			free_split_result(result_array);
			return (NULL);
		}
		i++;
	}
	result_array[i] = NULL;
	return (result_array);
}

void	free_split_result(char **result_array)
{
	int	i;

	if (result_array)
	{
		i = 0;
		while (result_array[i])
		{
			free(result_array[i]);
			i++;
		}
		free(result_array);
	}
}
