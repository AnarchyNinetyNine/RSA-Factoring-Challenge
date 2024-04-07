#include "factors.h"

/**
 * strtow - A function that splits a string into words.
 * @str: A given string.
 *
 * Return: An array of words.
 */

char **_strtok(char *str)
{
	int wCount = 0; /* WourdCount */
	char **arr;     /* The malloc'ed array */

	if (!str || strcmp(str, "") == 0)
		return (NULL); /* Exit if no string provided */

	wCount = wc(str); /* Get the wordCount */

	if (wCount == 0)
		return (NULL); /* Exit if no word found */

	arr = malloc(sizeof(char *) * (wCount + 1)); /* Allocate memory */

	if (!arr)
		return (NULL); /* Exit if cannot allocate memory */

	return (fill_array(arr, str, wCount)); /* Return an rray of words */
}
