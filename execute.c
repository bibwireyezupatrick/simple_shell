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
		char *argv[] = {command, NULL};

		if (execve(command, argv, environ) == -1)
		{
			perror(command);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
}

