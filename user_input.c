#include "shell.h"
/**
 *read_cmd- user_input function
 *@cmd: string name
 *@size: size of string
 */
void read_cmd(char *cmd, size_t size)
{
	if (fgets(cmd, size, stdin) == NULL)
	{
		if (feof(stdin))
		{
			j_print("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			j_print("Error while reading input. \n");
			exit(EXIT_FAILURE);
		}
	}
	cmd[strcspn(cmd, "\n"] = '\0';
}

