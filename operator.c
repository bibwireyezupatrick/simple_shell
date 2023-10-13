#include "shell.h"

/**
 * j_print - Custom print function
 * @str: The string to print
 */
void j_print(const char *str) 
{
	write(STDOUT_FILENO, str, strlen(str));
}
/**
 * j_execute_command- execting function
 * @command: strng name
 */
int j_execute_command(char *command)
{
	/* Implement code to execute a single command
	 * This function could use exec functions, fork, etc.
	 */
	j_print("Executing command: ");
	j_print(command);
	j_print("\n");

	/* Simulating command success (0) or failure (non-zero)*/
	return (0);
}
/**
 * j_handle_logical_operator- operation function
 * @input: string name
 */
void j_handle_logical_operators(char *input)
{
	char *token;
	char *delim = "&&||";
	token = strtok(input, delim);

	int last_status = 0;  /* Stores the return status of the previous command */

	while (token != NULL)
	{
		if (strstr(token, "&&") != NULL)
		{
			/* Handle && logical operator*/
			char *command = strtok(token, "&&");

			if (j_execute_command(command) == 0)
			{
				/* Command succeeded, continue to the next command*/
				last_status = 0;
			} 
			else 
			{
				/* Command failed, no need to execute the next command*/
				last_status = -1;
				break;
			}
		}
		else if (strstr(token, "||") != NULL)
		{
			/* Handle || logical operator*/
			char *command = strtok(token, "||");

			if (j_execute_command(command) == 0)
			{
				/* Command succeeded, no need to execute the next command*/
				last_status = 0;
				break;
			}
			else 
			{
				/* Command failed, continue to the next command*/
				last_status = -1;
			}
		}

		token = strtok(NULL, delim);
	}

	j_print("Overall status: ");
	j_print(last_status == 0 ? "Success" : "Failure");
	j_print("\n");
}
/**
 * main- main function
 * j_print: printing function
 * @input: string name
 * j_handle_logical_operators: operation function
 * Return: always 0
 */
int main(void)
{
	char input[] = "ls /var && echo Hello || date";

	j_print("Original Input: ");
	j_print(input);
	j_print("\n");

	j_handle_logical_operators(input);

	return (0);
}
