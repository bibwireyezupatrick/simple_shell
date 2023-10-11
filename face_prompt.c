#include "shell.h"
/**
 * main- main function
 * display:function shaws what to be displayed
 *
 * Return: always 0
 */
int main(void)
{
	char cmd[100];

	while (true)
	{
		display();
		read_cmd(cmd, sizeof(cmd));
		execute_cmd(cmd);
	}
	return (0);
}
