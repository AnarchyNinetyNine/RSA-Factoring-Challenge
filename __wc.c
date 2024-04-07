#include "factors.h"

/**
 * wc - Counts the words inside a given string.
 *@placeholder: A string.
 *
 *Return: # The word count (On Success).
 *        # 0 otherwise.
 */

size_t wc(char *placeholder)
{
	int wc = 0;       /* wordCount */
	int inWord = 0;   /* inside a word */
	int i = 0;        /* iterator */

	while (placeholder[i])
	{
		if (placeholder[i] != ' ' && inWord == 0)
		{
			inWord = 1; /* Open inWord mode */
			++wc; /* Increment the wordCount */
		}
		else if (placeholder[i] == '\n' && inWord == 1)
		{
			inWord = 0; /* Clode inWord mode */
			placeholder[i] = '\0'; /* Poison the string */
		}
		++i;
	}
	return (wc);
}
