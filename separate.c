#include "shell.h"

/**
 * j_print- Custom print function
 * @str: The string to print
 */
void j_print(const char *str)
{
	write(STDOUT_FILENO, str, strlen(str));
}
/**
 * j_execute_command- executing function
 *
 */
void j_execute_command(char *command)
{
    /**
     * Implement code to execute a single command
     *This function could use exec functions, fork, etc.
     */
	j_print("Executing command: ");
	j_print(command);
	j_print("\n");
}
/**
 * j_handle_semicolon- other function
 *
 * @input: string name
 */
void j_handle_semicolon(char *input)
{
	char *token;
	char *delim = ";";

	token = strtok(input, delim);

	while (token != NULL)
	{
		j_execute_command(token);
		token = strtok(NULL, delim);
	}
}
/**
 * main- main function
 * @input: string name
 * Return: always 0
 */
int main(void)
{
	char input[] = "ls /var ; echo Hello ; date";

	j_print("Original Input: ");
	j_print(input);
	j_print("\n");

	j_handle_semicolon(input);

	return (0);
}
