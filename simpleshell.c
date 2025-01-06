#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include <sys/stat.h>

int main(void)
{
	size_t linesize = 65;
	char *line = NULL;
	const char *delimiter = " ";
	builtin_t builtins[] = {{"env", env_command},{"exit", exit_command},
	{NULL, NULL}};
	int i, j, bool1;

	printf("\033[H\033[J");
	if (isatty(STDOUT_FILENO)) {
	while (1)
	{
	bool1 = 0;
        printf("HMShell:~$ ");
        if (getline(&line, &linesize, stdin) == -1)
            break;
	for (j = 0; line[j] != '\n'; j++);
	line[j] = '\0';
	for (i = 0; builtins[i].name != NULL; i++)
	{
		if (_strcmp(builtins[i].name, line) == 0)
		{
			builtins[i].func(line);
			bool1 = 1;
			break;
		}
	}
	if (bool1 == 1)
		continue;
	if (couleur(line) == 0)
		continue;
	execute_command(line, delimiter);
	}
    return (0);
}
