/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrol-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 20:58:11 by jbrol-ca          #+#    #+#             */
/*   Updated: 2024/12/20 13:09:23 by jbrol-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static int	count_words(char *str, char delim)
{
	int		word_count;
	int		in_word;

	word_count = 0;
	in_word = 0;
	while (*str)
	{
		while (*str == delim)
			++str;
		while (*str != delim && *str)
		{
			if (in_word == 0)
			{
				++word_count;
				in_word = 1;
			}
			++str;
		}
		in_word = 0;
	}
	return (word_count);
}

static char	*get_next_word(char *str, char delim)
{
	static int	index = 0;
	char		*word;
	int			length;
	int			j;

	length = 0;
	j = 0;
	while (str[index] == delim)
		++index;
	while ((str[index + length] != delim) && str[index + length])
		++length;
	word = malloc((size_t)length + 1);
	if (!word)
		return (NULL);
	while ((str[index] != delim) && str[index])
		word[j++] = str[index++];
	word[j] = '\0';
	return (word);
}

char	**split(char *s, char c)
{
	int		words_count;
	char	**result_array;
	int		i;

	i = 0;
	words_count = count_words(s, c);
	if (!words_count)
		exit(1);
	result_array = malloc(sizeof(char *) * (size_t)(words_count + 2));
	if (!result_array)
		return (NULL);
	while (words_count-- > 0)
	{
		if (i == 0)
		{
			result_array[i] = malloc(sizeof(char));
			if (!result_array[i])
				return (NULL);
			result_array[i++][0] = '\0';
			continue ;
		}
		result_array[i++] = get_next_word(s, c);
	}
	result_array[i] = NULL;
	return (result_array);
}

void	free_split_result(char **result_array)
{
	int	i;

	i = 0;
	if (!result_array)
		return ;
	while (result_array[i])
	{
		free(result_array[i]);
		i++;
	}
	free(result_array);
}
