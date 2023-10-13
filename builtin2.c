#include "shell.h"

/**
 * j_print - Custom print function
 * @str: The string to print
 */
void j_print(const char *str)
{
	write(STDOUT_FILENO, str, strlen(str));
}

int j_cd(char *path)
{
	if (path == NULL)
	{
		path = getenv("HOME");  /* If no argument, change to home directory*/
	}

	if (chdir(path) != 0)
	{
		j_print("Error changing directory\n");
		return (-1);
	}

	char *cwd = getcwd(NULL, 0);

	if (cwd == NULL)
	{
		j_print("Error getting current directory\n");
		return (-1);
	}

	/* Update PWD environment variable*/
	j_setenv("PWD", cwd);

	j_print("Current directory: ");
	j_print(cwd);
	j_print("\n");

	free(cwd);
	return (0);
}
/**
 * main- main function
 * path: string name
 *j_cd: path
 * Return: always 0
 */
int main(void)
{
	char path[] = "/tmp";

	j_cd(path);

	return (0);
}

