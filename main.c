#include "factors.h"

int main(int ac, char **av)
{
	(void)ac;
	char *string, *endptr;
	char *filename;
	size_t letters;
	char **tokens;
	int i;
	
	if (ac != 2)
	{
		printf("Usage: factors <file>\n");
		exit(EXIT_FAILURE);
	}
	filename = av[1];
	letters = 1024 * 8;
	void tokenizer()
	{
		string = read_textfile(filename, letters);
		tokens = _strtok(string);
		while(*tokens)
		{
			for (i = 2; i <= strtoull(*tokens, &endptr, 10) + 1; i++)
			{
				if (strtoull(*tokens, &endptr, 10) % i == 0)
				{
					printf("%lld=%lld*%d\n", strtoull(*tokens, &endptr, 10), strtoull(*tokens, &endptr, 10) / i, i);
					break;
				}
			}
			++tokens;
		}
	}
	tokenizer();
	return (0);
}
