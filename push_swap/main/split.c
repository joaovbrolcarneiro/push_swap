#include "../../inc/push_swap.h"

static int	count_words(char *str, char delim) 
// Function to count how many words (substrings) are in a string separated by a delimiter
{
	int		word_count; // Counts the number of words in the string
	bool	in_word; // Indicates if we are inside a word or a delimiter

	word_count = 0;
	while (*str) // Iterates until the end of the string
	{
		in_word = false; // Resets the state for each iteration
		while (*str == delim) // Skips consecutive delimiters
			++str;
		while (*str != delim && *str) // Processes until a delimiter or the end of the string is encountered
		{
			if (!in_word) // If we are entering a new word
			{
				++word_count; // Increments the word counter
				in_word = true; // Updates the state to inside a word
			}
			++str; // Advances to the next character
		}
	}
	return (word_count);
}

static char	*get_next_word(char *str, char delim) 
// Function to extract the next word (substring) from the string
{
	static int	index = 0; // Current position in the string, preserved between calls
	char		*word; // Pointer to the newly extracted word
	int			length; // Length of the current word
	int			j; // Index to copy characters to the new word

	length = 0;
	j = 0;
	while (str[index] == delim) // Skips delimiters consecutively
		++index;
	while ((str[index + length] != delim) && str[index + length]) 
		// Calculates the length of the word until a delimiter or end of string is encountered
		++length;
	word = malloc((size_t)length * sizeof(char) + 1); 
	// Allocates memory for the new word, including the null terminator
	if (!word) // Checks if memory allocation failed
		return (NULL);
	while ((str[index] != delim) && str[index]) 
		// Copies characters from the word into the newly allocated memory
		word[j++] = str[index++];
	word[j] = '\0'; // Terminates the word with a null character
	return (word);
}

char	**split(char *str, char delim) 
// Function to split a string into substrings based on a delimiter
{
	int		word_total; // Stores the total number of words in the string
	char	**split_array; // Pointer to the array of resulting words
	int		k; // Index to iterate through the array of words

	k = 0;
	word_total = count_words(str, delim);
	if (!word_total) // If there are no words
		exit(1);
	split_array = malloc(sizeof(char *) * (size_t)(word_total + 2)); 
	// Allocates memory for the word array
	if (!split_array) // Checks if memory allocation failed
		return (NULL);
	while (word_total-- >= 0) // Processes all words
	{
		if (k == 0) // For the first character in the string
		{
			split_array[k] = malloc(sizeof(char)); 
			// Allocates memory for an empty string
			if (!split_array[k]) // Checks if memory allocation failed
				return (NULL);
			split_array[k++][0] = '\0'; 
			// Adds an empty string in the array as a distinct element
			continue ;
		}
		split_array[k++] = get_next_word(str, delim); 
		// Extracts the next word and stores it in the array
	}
	split_array[k] = NULL; // Terminates the array with a null pointer
	return (split_array);
}LoPer