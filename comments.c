#include "shell.h"
/**
 * j_print - Custom print function
 * @str: The string to print
 */
void j_print(const char *str)
{
	write(STDOUT_FILENO, str, strlen(str));
}
/**
 *main- main function
 *input: string name
 *Return: always 0
 */
int main(void)
{
	char input[] = "echo $$ # ls -la";

	j_print("Original Input: ");
	j_print(input);
	j_print("\n");

	char *pos = strstr(input, "#");

	if (pos != NULL)
	{
		*pos = '\0';
	}

	j_print("Processed Input: ");
	j_print(input);
	j_print("\n");

	return (0);
}

