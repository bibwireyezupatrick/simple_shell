#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main(void)
{
char *input = NULL;
size_t i = 0;
while(1)
{

printf("eso_shell$ ");
size_t get_line = getline(&input, &i, stdin);
if (get_line == -1 || strcmp(input, "exit\n") == 0)
{
free(input);
break;
}

if(strcmp (input, "ls\n") == 0)
{

char *argv[] = {"ls", NULL};
pid_t pid = fork();
if(pid ==-1)
{
printf("errorr");
}
if(pid == 0)
{
int exec_prog = execve("/bin/ls", argv, NULL);
	}
wait(NULL);
free(input);
continue;

}
continue;
}

}
