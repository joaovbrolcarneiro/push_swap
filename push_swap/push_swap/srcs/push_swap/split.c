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
	bool	in_word;

	word_count = 0;
	while (*str)
	{
		in_word = false;
		while (*str == delim)
			++str;
		while (*str != delim && *str)
		{
			if (!in_word)
			{
				++word_count;
				in_word = true;
			}
			++str;
		}
	}
	return (word_count);
}

static char	*get_next_word(char *str, char delim)
/* Function to extract the next word (substring) from the string */
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
	word = malloc((size_t)length * sizeof(char) + 1);
	if (!word)
		return (NULL);
	while ((str[index] != delim) && str[index])
		word[j++] = str[index++];
	word[j] = '\0';
	return (word);
}
