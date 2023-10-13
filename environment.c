#include "shell.h"
/**
 * j_print- custom print function
 * @str: string name
 */
void j_print(const char *str)
{
	write(STDOUT_FILENO, str, strlen(str));
}
/**
 * main- main function
 * @argc: integer
 * @argv: argument vector
 * @envp: string name
 *
 * Return: always 0
 */
int main(int argc, char *argv[], char *envp[])
{
	(void)argc;
	(void)argv;

	char *command = NULL;
	size_t bufsize = 0;

	while (1)
	{
		j_print("($) ");
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
				j_print(*env);
				j_print("\n");
			}
		}

		j_print("Command executed: ");
		j_print(command);
		free(command);
	}

	return (0);
}

