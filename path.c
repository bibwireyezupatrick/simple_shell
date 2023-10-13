#include "shell.h"
/**
 * j_print- printing function
 * @str: string name
*/
void j_print(const char *str)
{
	write(STDOUT_FILENO, str, strlen(str));
}
/**
 * main- main function
 * @str: string name
 *
 * Return: always 0
*/
int main(void)
{
	char *command = NULL;
	char *token;  /* Declare token here*/
	size_t bufsize = 0;

	while (1) 
	{
		j_print("(Japhspace$) ");
		if (getline(&command, &bufsize, stdin) == -1)
		{
			perror("getline");
			free(command);
			exit(EXIT_FAILURE);
		}

		/* Tokenize the command and execute it*/
		token = strtok(command, " \n"); /* Assign value to token here*/
		if (token != NULL)
		{
			 /* Rest of your code remains the same*/
		}
	}
	free(command);
	return (0);
}
