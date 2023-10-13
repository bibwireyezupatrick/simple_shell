#include "shell.h"
/**
 * main- main function
 *
 * Return: always 0
 */
int main(void)
{
	char *command = NULL;
	size_t bufsize = 0;

	while (1)
	{
		j_print("(Japhspace) ");
		if (getline(&command, &bufsize, stdin) == -1)
		{
			perror("getline");
			free(command);
			exit(EXIT_FAILURE);
		}

		if (strcmp(command, "exit\n") == 0)
		{
			free(command);
			exit(0);
		}
		/* Execute the command*/
		j_print("Command executed: %s", command);
	}

	free(command);
	return (0);
}
