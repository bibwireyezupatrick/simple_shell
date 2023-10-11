#include "shell.h"

/**
 * j_print - our printf function
 * @printing: string name
 */
void j_print(const char *printing)
{
	write(STDOUT_FILENO, printing, strlen(printing));
}

