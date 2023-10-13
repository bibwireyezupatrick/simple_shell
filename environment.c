#include "shell.h"
/**
 * main- main function
 *@argv: arguiment vector
 *@argc: arguiment
 *@envp: string name
 *
 * Return: always 0
 */


int main(int argc, char *argv[], char *envp[])
{
	(void)argc;
	(void)argv;

	while (1)
	{
		j_print("(Japhspace) ");
		char *command = NULL;
		size_t bufsize = 0;

		if (getline(&command, &bufsize, stdin) == -1)
		{
			perror("getline");
			free(command);
			exit(EXIT_FAILURE);
		}

		if (strcmp(command, "env\n") == 0)
		{
			char **env;

			for (env = envp; *env != NULL; env++)
			{
				j_print("%s\n", *env);
			}
		}
		/* Execute the command */
		j_print("Command executed: %s", command);
		free(command);
	}

	return (0);
}

