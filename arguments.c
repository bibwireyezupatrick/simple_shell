#include "shell.h"

/**
 * j_print - Printing function
 * @str: The string to print
 *
 */
void j_print(const char *str)
{
	write(STDOUT_FILENO, str, strlen(str));
}

/**
 * main - Main function
 *@command: string name
 * Return: Always returns 0
 */
int main(void)
{
	char *command = NULL;
	size_t bufsize = 0;

	while (1)
	{
		j_print("(Japhspace$) ");
		getline(&command, &bufsize, stdin);

		/* Tokenize the command and execute it */
		char *token;

		token = strtok(command, " \n");

		while (token != NULL)
		{
			j_print("Argument: ");
			j_print(token);
			j_print("\n");
			token = strtok(NULL, " \n");
		}
	}

	free(command);
	return (0);
}

