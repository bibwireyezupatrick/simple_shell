#include "shell.h"
/**
 * j_print - Custom print function
 * @str: The string to print
 */
void j_print(const char *str)
{
	write(STDOUT_FILENO, str, strlen(str));
}

int j_setenv(char *var, char *value)
{
	if (setenv(var, value, 1) != 0)
	{
		j_print("Error setting environment variable\n");
		return (-1);
	}
	j_print("Environment variable set: ");
	j_print(var);
	j_print("=");
	j_print(value);
	j_print("\n");
	return (0);
}

int j_unsetenv(char *var)
{
	if (unsetenv(var) != 0)
	{
		j_print("Error unsetting environment variable\n");
		return (-1);
	}
	j_print("Environment variable unset: ");
	j_print(var);
	j_print("\n");
	return (0);
}
/**
 * main- main function
 * var: string name
 * value: my value
 *
 * Return: always 0
 */
int main(void)
{
	char var[] = "MY_VARIABLE";
	char value[] = "my_value";
	char var_to_unset[] = "TO_BE_UNSET";

	j_setenv(var, value);
	j_unsetenv(var_to_unset);

	return (0);
}

