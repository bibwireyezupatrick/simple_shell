#include "shell.h"

/**
 * j_print- Custom print function
 * @str: The string to print
 */
void j_print(const char *str)
{
	write(STDOUT_FILENO, str, strlen(str));
}

/* Structure to store environment variables*/
typedef struct EnvVar
{
	char *name;
	char *value;
	struct EnvVar *next;
}
EnvVar;
EnvVar *env_vars = NULL;
/**
 * j_execute_command- executing command
 * @command: string to print
 */
int j_execute_command(char *command)
{
	/* Implement code to execute a single command
	 * * This function could use exec functions, fork, etc.
	 * */
	j_print("Executing command: ");
	j_print(command);
	j_print("\n");

    /* Simulating command success (0) or failure (non-zero)*/

	return (0);
}
/**
 * j_get_env- getting function
 * @name: string name
 * Return: NULL 0
 */
char *j_get_env(const char *name)
{
	/*Find and return the value of an environment variable*/
	EnvVar *env = env_vars;
	while (env != NULL)
	{
		if (strcmp(env->name, name) == 0)
		{
			return env->value;
		}
		env = env->next;
	}
	return NULL;
}
/**
 * j_set_env- environment function
 * @name: string name
 * @value: string name
 * Return: always 0
 */
int j_set_env(const char *name, const char *value)
{
	/* Set or update an environment variable*/
	EnvVar *env = env_vars;
	while (env != NULL)
	{
		if (strcmp(env->name, name) == 0)
		{
			free(env->value);
			env->value = strdup(value);
			return (0);
		}
		env = env->next;
	}
	env = malloc(sizeof(EnvVar));
	env->name = strdup(name);
	env->value = strdup(value);
	env->next = env_vars;
	env_vars = env;
	return (0);
}
/**
 * j_handle_variables- function of valiables
 * @input: string name
 */
void j_handle_variables(char *input)
{
	char *token;
	char *delim = " ";
	token = strtok(input, delim);

	while (token != NULL)
	{
		if (token[0] == '$' && token[1] != '\0')
		{
            /* It's an environment variable*/
			char *name = token + 1;
			char *value = j_get_env(name);
            
			if (value != NULL)
			{
				/* Replace the variable with its value*/
				write(STDOUT_FILENO, value, strlen(value));
				write(STDOUT_FILENO, " ", 1);  /* Add a space after the value*/
			}
		}
		else
		{
			/* Not an environment variable, execute the command*/
			j_execute_command(token);
		}
		token = strtok(NULL, delim);
	}
	j_print("\n");
}

/**
 * main- main function
 * @input: string name
 * j_set_env: environment function
 * Return: always 0
 */
int main(void)
{
	char input[] = "ls $HOME -la";

	j_print("Original Input: ");
	j_print(input);
	j_print("\n");

	/* Simulate setting an environment variable*/
	j_set_env("HOME", "/home/user");
	j_handle_variables(input);

	return (0);
}
