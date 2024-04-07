#include "factors.h"

void _tokenizer(char *filename) {
	size_t letters = 1024 * 8;
	char *string = read_textfile(filename, letters);
	char **tokens = _strtok(string);
	mpz_t number, modulus, modulus_result, divisor, quotient;
	int i;
	time_t current_time;

	mpz_init(number);
	mpz_init(divisor);
	mpz_init(quotient);
	mpz_init(modulus_result);

	while (*tokens)
	{
		current_time = time(NULL);
		mpz_set_str(number, *tokens, 10);

		for (i = 2; i <= mpz_get_ui(number) + 1; i++)
		{
			if (time(NULL) - current_time > 5)
				exit(1);
			mpz_init_set_ui(modulus, i);
			mpz_init_set_ui(divisor, i);
			mpz_mod(modulus_result, number, modulus);
			mpz_div(quotient, number, divisor);

			if (mpz_cmp_ui(modulus_result, 0) == 0)
			{
				gmp_printf("%Zd=%Zd*%d\n", number, quotient, i);
				break;
			}
		}

		tokens++;
	}

	/* Clean up mpz_t variables */
	mpz_clear(number);
	mpz_clear(divisor);
	mpz_clear(quotient);
	mpz_clear(modulus_result);
}

int main(int argc, char **argv) {
	if (argc != 2)
	{
		printf("Usage: factors <file>\n");
		exit(EXIT_FAILURE);
	}

	_tokenizer(argv[1]);
	return (0);
}
