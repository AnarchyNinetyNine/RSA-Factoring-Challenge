#include "factors.h"

/**
 * tokenizer - Retrieves words from a given string.
 * @placeholder: An address of a pointer to a string.
 *
 * Return: A word from the string.
 */

char *tokenizer(char **placeholder)
{
	char *word;
	char *str = *placeholder;

	while (*str)
	{
		if (*str != ' ')
		{
			word = str;
			while (*str != '\0')
				++str;

			*placeholder = ++str;
			return (word);
		}
		++str;
	}
	return (NULL);
}
