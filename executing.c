#include "shell.h"
/**
 * execute_cmd- executing function
 * child_pid: child process id
 * @cmd: string name
 */
void execute_cmd(const char *cmd)
{
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		const char *args[] = {cmd, NULL};
		const char *envp[] = {NULL};

		if (execve(cmd, args, envp) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}
}
