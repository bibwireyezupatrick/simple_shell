#include"shell.h"

/**
 * j_print - Custom print function
 * @str: The string to print
 */
void j_print(const char *str)
{
	write(STDOUT_FILENO, str, strlen(str));
}
int j_exit(char *status)
{
	int exit_status = atoi(status);

	j_print("Exiting with status: ");
	j_print(status);
	j_print("\n");
	exit(exit_status);
}
/**
 * main- mainfunction
 * Return: always 0
 * @status: string name
 *
 */
int main(void)
{
	char status[] = "42";

	j_exit(status);
	/* The program will exit with status 42 */

	return (0);
}
