#include "monty.h"

#define IN  1	/* inside a word */
#define OUT 0	/* outside a word */

/**
 * words_count - counts the number of words in a string
 *
 * @str: a pointer to the string
 * Return: the number of words in the string
 */
size_t words_count(const char *str)
{
	size_t words;
	int state;

	state = OUT;
	words = 0;
	while (*str != '\0')
	{
		if (*str == ' ' || *str == '\t')
			state = OUT;
		else if (state == OUT)
		{
			state = IN;
			++words;
		}
		++str;
	}
	return (words);
}

/**
 * strtow - splits a string into words
 * @str: a pointer to the string to splitted
 * Return: a pointer to an array of strings
 * or NULL if malloc fails
 */
char **strtow(char *str)
{
	char **words, *tmp;
	int n_words, len, i;

	n_words = words_count(str);
	if (str == NULL || *str == '\0' || n_words == 0)
		return (NULL);

	words = (char **) malloc(sizeof(char *) * (n_words + 1));
	if (words == NULL)
		return (NULL);

	for (i = 0; i < n_words; i++)
	{
		/* Skip a sequence of spaces */
		while (*str == ' ' || *str == '\t')
			str++;

		/* get the length of the next word */
		len = 0;
		while (str[len] != ' ' && str[len] != '\t' && str[len] != '\0')
			len++;

		words[i] = (char *) malloc(sizeof(char) * (len + 1));
		if (words[i] == NULL)
		{
			while (i--)
				free(words[i]);
			free(words);
			return (NULL);
		}
		/* Copy substring into array */
		for (tmp = words[i]; tmp < words[i] + len; tmp++)
			*tmp = *str++;
		*tmp = '\0';
	}
	words[i] = NULL;
	return (words);
}
