#include "shell.h"

/**
 *
 * j_print - Custom print functio
 * getline: function to print new line
 * @str: The string to print
 *
 */
void j_print(const char *str)
{
	write(STDOUT_FILENO, str, strlen(str));
}
char *j_getline(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	ssize_t n;

	j_print("$ ");  /* Display shell prompt*/
	n = getline(&line, &bufsize, stdin);
	if (n == -1)
	{
		j_print("Error reading input\n");
		exit(EXIT_FAILURE);
	}
	return(line);
}
/**
 * main- main function
 * Return: always 0
 */
int main(void)
{
	char *input;

	input = j_getline();
	j_print("You entered: ");
	j_print(input);
	free(input);
	return(0);

