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
		j_print("($) ");
		if (getline(&command, &bufsize, stdin) == -1)
		{
			perror("getline");
			free(command);
			exit(EXIT_FAILURE);
		}

		/*Tokenize the command and execute it*/
		char *token = strtok(command, " \n");

		if (token != NULL)
		{
			/* Try to execute the command directly*/
			if (access(token, X_OK) == 0)
			{
				pid_t child_pid = fork();

				if (child_pid == -1)
				{
					perror("fork");
					free(command);
					exit(EXIT_FAILURE);
				}
				if (child_pid == 0)
				{
					/* Child process*/
					execve(token, &token, environ);
					perror("execve");
					free(command);
					exit(EXIT_FAILURE);
				}
				else
				{
					/* Parent process */
					int status;

					wait(&status);
				}
			}
			else
			{
				j_print("Command not found: %s\n", token);
			}
		}
	}

	free(command);
	return (0);
}

