#include "shell.h"
/**
 * execute_command- executing function
 * child_pid: child process
 * @command: string name
 */
void execute_command(char *command)
{
	pid_t child_pid;
	int status;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");

		return;
	}
	if (child_pid == 0)
	{
		/* Child process */

		/* Tokenize the command into an argument array*/
		char *argv[2];

		argv[0] = command;
		argv[1] = NULL;

		if (execve(command, argv, environ) == -1)
		{
			char error_message[100];

			snprintf(error_message, sizeof(error_message), "./hsh: 1: %s: not found\n", command);
			j_print(error_message);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/* Parent process */
		wait(&status);
	}
}

