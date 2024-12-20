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

char	**split(char *s, char c) // Define a function that returns the substrings in a string separated by a delimiter
{
	int		words_count; // Used to keep track of the number of substrings in the string
	char	**result_array; // To store a pointer to pointers, the array of all the substrings
	int		i; // Used to iterate through the array

	i = 0;
	words_count = count_words(s, c);
	if (!words_count) // Check for `0` words
		exit(1);
	result_array = malloc(sizeof(char *) * (size_t)(words_count + 2)); // Allocate memory for the result_array based on the number of words (words_count) plus two additional slots
	if (!result_array) // Check for unsuccessful memory allocation
		return (NULL);
	while (words_count-- > 0) // Iterates through the words to be split, all words have been processed
	{
		if (i == 0) // Check if the first character of the input string is the delimiter
		{
			result_array[i] = malloc(sizeof(char)); // Allocate memory for an empty string (a single null terminator)
			if (!result_array[i]) // Check for unsuccessful memory allocation
				return (NULL);
			result_array[i++][0] = '\0'; // Include in the result array as distinct elements
			continue ;
		}
		result_array[i++] = get_next_word(s, c); // Extract the substring and copy it into the result array
	}
	result_array[i] = NULL; // Properly null terminate the array
	return (result_array);
}
