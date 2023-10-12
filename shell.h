#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sdtbool.h>
#include <sys/types.h>
#include <sys/wait.h>

void j_print(const char *printing);
void display(void);
void execute_cmd(const char *cmd);
void read_cmd(char *cmd, size_t size);





#endif /* SHELL_H */
