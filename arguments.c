#include "shell.h"
/**
* j_print- printing function
*/
void j_print(const char *str)
{
	write(STDOUT_FILENO, str, strlen(str));
}
/**
* main- main function
* @command: string name
*/
int main(void)
{
	char *command = NULL;
	size_t bufsize = 0;

	while (1)
	{
		j_print("($) ");
		getline(&command, &bufsize, stdin);

        /*Tokenize the command and execute it*/
		char *token = strtok(command, " \n");

		while (token != NULL)
		{
			j_print("Argument: ");
			j_print(token);
			j_print("\n");
			token = strtok(NULL, " \n");
		}
	}
	free(command);
	return (0);
}
