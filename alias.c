#include "shell.h"

/**
 * j_print - Custom print function
 * @str: The string to print
 */
void j_print(const char *str)
{
	write(STDOUT_FILENO, str, strlen(str));
}

/* Structure to store aliases*/
typedef struct Alias
{
	char *name;
	char *value;
	struct Alias *next;
} Alias;

Alias *aliases = NULL;

void j_execute_command(char *command)
{
	/* Implement code to execute a single command*/
	/* This function could use exec functions, fork, etc.*/
	j_print("Executing command: ");
	j_print(command);
	j_print("\n");
}

void j_handle_alias(char *input)
{
	if (strncmp(input, "alias", 5) == 0)
	{
		/* Handling alias command*/
		if (strlen(input) > 6)
		{
			char *alias_def = input + 6; /* Skip "alias " part*/
			char *name = strtok(alias_def, "=");
			char *value = strtok(NULL, "=");

			/*Store or update the alias*/
			Alias *alias = aliases;
			while (alias != NULL)
			{
				if (strcmp(alias->name, name) == 0)
				{
					free(alias->value);
					alias->value = strdup(value);
					return;
				}
				alias = alias->next;
			}
			alias = malloc(sizeof(Alias));
			alias->name = strdup(name);
			alias->value = strdup(value);
			alias->next = aliases;
			aliases = alias;
		}
		else
		{
			/* Print all aliases*/
			Alias *alias = aliases;
			while (alias != NULL)
			{
				j_print("alias ");
				j_print(alias->name);
				j_print("='");
				j_print(alias->value);
				j_print("'\n");
				alias = alias->next;
			}
		}
		}
		else 
		{
		/*Check if the command is an alias*/
		Alias *alias = aliases;

		while (alias != NULL)
		{
		if (strcmp(input, alias->name) == 0)
		{
		input = alias->value;
		break;
		}
		alias = alias->next;
		}
		j_execute_command(input);
		}
}
/**
 * main- main function
 * input: string name
 *
 * Return: always 0
 */
int main(void)
{
	char input[] = "ls /var";

	j_print("Original Input: ");
       	j_print(input);
	j_print("\n");

	j_handle_alias(input);

	return (0);
}

