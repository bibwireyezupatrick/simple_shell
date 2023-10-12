#include "shell.h"
/**
 * main- main function
 *
 * Return: always 0
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;

	while (1)
	{
		j_print("(Japhspace$) "); /* Display the prompt*/
		getline(&line, &len, stdin);

		if (line == NULL)
		{
			j_print("\n"); /* Print a newline on Ctrl+D */
			break;
		}
		/* Remove the newline character from the input */
		if (line[strlen(line) - 1] == '\n')
			line[strlen(line) - 1] = '\0';
		/* Execute the command */
		execute_command(line);

		/* Free allocated memory */
		free(line);
		line = NULL;
	}

	return (0);
}

