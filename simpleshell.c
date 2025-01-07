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
	int i, j, bool1, last_return = 0, line_number = 1, eof_count = 0;

	(void)argc;
	while (1)
	{
		bool1 = 0;
		if (isatty(STDIN_FILENO))
			printf("$ ");
		if (getline(&line, &linesize, stdin) == -1)
		{
			if(end_of_file(line, argv, &line_number, &eof_count) == 1)
			{
				line = NULL;
				continue;
			}
			else
			{
				free(line);
				break;
			}
		}

		for (j = 0; line[j] != '\n' && line[j] != '\0'; j++)
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
		{
			free(line);
			continue;
		}
		last_return = execute_command(line, delimiter, argv[0], line_number);
		free(line);
		line = NULL;
		line_number++;
	}
	return (last_return);
}
/*cette fonction ne fonctionne qu'à moitié, eof_count n'atteint jamais 2 ce qui nique tout*/
int end_of_file(char *line, char **argv, int *line_number, int *eof_count)
{
	int bool2 = 0, i;
	const char *delimiter = " ";
	builtin_t builtins[] = {{"env", env_command}, {"exit", exit_command}, {NULL, NULL}};

	if (line == NULL || *line == '\0')
	{
		write(STDOUT_FILENO, "\n", 1);
		return (0);
	}
	(*eof_count)++;
	/*test*/
	printf("count de ce fils de pute : %d", *eof_count);
	/*----*/
	 if (*eof_count == 2)
	{
		for (i = 0; builtins[i].name != NULL; i++)
		{
			if (_strcmp(builtins[i].name, line) == 0)
			{
				builtins[i].func(line);
				bool2 = 1;
				break;
			}
		}
		if (bool2 == 1)
		{
			return (1);
		}
		execute_command(line, delimiter, argv[0], *line_number);
		(*line_number)++;
		line = NULL;
		return (1);
	}
	return (0);
}

