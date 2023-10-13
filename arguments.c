#include "shell.h"
/**
 * main- main function
 * command: string name
 *
 * Return: always 0
 */
int main(void)
{
	char *command = NULL;
	size_t bufsize = 0;

	while (1)
	{
		j_print("(Japhspace)");
		if (getline(&command, &bufsize, stdin) == -1)
		{
			perror("getline");
			free(command);
			exit(EXIT_FAILURE);
		}

		/* Tokenize the command and execute it*/
		char *token = strtok(command, " \n");

		while (token != NULL)
		{
			j_print("Argument: %s\n", token);
			token = strtok(NULL, " \n");
		}
	}

	free(command);

	return (0);
}
