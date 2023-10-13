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
 * main- main function
 * argc: integer
 * argv: arguiment vector
 *
 * Return: always 1
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		j_print("Usage: simple_shell [filename]\n");
		return (1);
	}

	FILE *file = fopen(argv[1], "r");

	if (file == NULL)
	{
		j_print("Error: Could not open file.\n");
		return (1);
	}

	char line[1024];

	while (fgets(line, sizeof(line), file))
	{
		line[strcspn(line, "\n")] = '\0';
		j_print("Executing: ");
		j_print(line);
		j_print("\n");
	}

	fclose(file);
	return (0);
}

