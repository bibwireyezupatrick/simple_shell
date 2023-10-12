#include "shell.h"
/**
 *j_print- in place of printf function
 *@printer: string name
 */
void j_print(const char *printer)
{
	write(STDOUT_FILENO, printer, strlen(printer));
}
