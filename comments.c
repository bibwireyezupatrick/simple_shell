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
 * main - Main function
 *
 * Return: Always returns 0
 */
int main(void)
{
	char input[] = "echo $$ # ls -la";
	char *pos;

	j_print("Original Input: ");
	j_print(input);
	j_print("\n");

	pos = strstr(input, "#");

	if (pos != NULL)
	{
		*pos = '\0';
	}

	j_print("Processed Input: ");
	j_print(input);
	j_print("\n");

	return (0);
}

