#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include <sys/stat.h>
/**
 * main - Entry point for the HMShell program
 *
 *
 * description: This program implements a basic shell that supports built-in
 * commands (e.g., "env", "exit") and executes external commands.
 * It continuously
 * prompts the user for input, processes the input, and executes commands until
 * an exit condition is met.
 *
 * Return: Always returns 0 upon successful execution.
 */
int main(int argc, char **argv)
{
	size_t linesize = 65;
	char *line = NULL;
	const char *delimiter = " ";
	builtin_t builtins[] = {{"env", env_command},
	{"exit", exit_command}, {NULL, NULL}};
	int i, j, bool1, last_return = 0;

	(void)argc;
	/* printf("\033[H\033[J"); */
	while (1)
	{
		bool1 = 0;
		if (isatty(STDIN_FILENO))
		{
			printf("HMShell:~$ ");
		}
		if (getline(&line, &linesize, stdin) == -1)
			break;
		for (j = 0; line[j] != '\n'; j++)
			;
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
		last_return = execute_command(line, delimiter, argv[0]);
	}
	return (last_return);
}
