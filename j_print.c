#include "shell.h"
/**
 *j_print- in place of printf function
 *@printer: string name
 */
void j_print(const char *message)
{
	write(STDOUT_FILENO, message, strlen(message));
}
