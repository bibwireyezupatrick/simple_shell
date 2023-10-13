#include "sheel.h"

/**
 * j_print - Custom print function
 * @str: The string to print
 */
void j_print(const char *str)
{
	write(STDOUT_FILENO, str, strlen(str));
}
/**
 * main - main function
 * @input: The string to print
 */
int main(void)
{
	char input[] = "echo $$ # ls -la";

	j_print("Original Input: ");
	j_print(input);
	j_print("\n");

	char *pos; /* Declare pos at the beginning of the block*/

	pos = strstr(input, "#");
	if (pos != NULL)
	{
		*pos = '\0';
	}

	j_print("Processed Input: ");
	j_print(input);
	j_print("\n");
	return 0;
}
