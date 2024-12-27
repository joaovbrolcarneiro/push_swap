/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrol-ca <jbrol-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 20:58:11 by jbrol-ca          #+#    #+#             */
/*   Updated: 2024/12/27 12:38:17 by jbrol-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static int	count_words(char *str, char delim)
{
	int	word_count = 0;
	int	in_word = 0;

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
	int		length = 0;

	while (**str_ptr && **str_ptr == delim)
		(*str_ptr)++;
	start = *str_ptr;
	while ((*str_ptr)[length] && (*str_ptr)[length] != delim)
		length++;
	word = malloc((length + 1) * sizeof(char));
	if (!word)
		return (NULL);
	for (int i = 0; i < length; i++)
		word[i] = start[i];
	word[length] = '\0';
	*str_ptr += length;
	return (word);
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
	result_array = malloc((words_count + 2) * sizeof(char *)); // +1 for result_array[0], +1 for NULL
	if (!result_array)
		return (NULL);
	result_array[0] = malloc(1); // Allocate for "\0"
	if (!result_array[0])
	{
		free(result_array);
		return (NULL);
	}
	result_array[0][0] = '\0';
	str_ptr = s;
	i = 1; // Start filling from index 1
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
	result_array[i] = NULL; // Null-terminate the array
	return (result_array);
}

void	free_split_result(char **result_array)
{
	int	i;

	if (!result_array)
		return;
	for (i = 0; result_array[i]; i++)
		free(result_array[i]);
	free(result_array);
}
