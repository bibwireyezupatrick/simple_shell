#include "shell.h"

/**
 * j_print - Custom print function
 * @str: The string to print
 * j_tokenize: tokenization input
 */
void j_print(const char *str)
{
	write(STDOUT_FILENO, str, strlen(str));
}

void j_tokenize(char *input)
{
	char *token;
	char *delim = " \t\n";  /* Define your own delimiters*/

	token = strtok(input, delim);

	while (token != NULL)
	{
		j_print("Token: ");
		j_print(token);
		j_print("\n");
		token = strtok(NULL, delim);
	}
}
/**
 * main- main function
 *
 * Return: always 0
 */
int main(void)
{
	char input[] = "This is a test input";

	j_print("Original Input: ");
	j_print(input);
	j_print("\n");

	j_tokenize(input);

	return (0);
}

