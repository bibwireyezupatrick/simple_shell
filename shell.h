#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

void j_print(const char *message);
void execute_command(char *command);
void read_command(char *command, size_t size);
extern char **environ;





#endif /* SHELL_H */
