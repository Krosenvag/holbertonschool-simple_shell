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
 * @argc: count the number of args
 * @argv: list of args
 * Return: Always returns 0 upon successful execution.
 */
int main(int argc, char **argv)
{
	size_t linesize = 65, newline_index = 0;
	char *line = NULL;
	const char *delimiter = " ";
	builtin_t builtins[] = {{"env", env_command},
		{"exit", exit_command}, {NULL, NULL}};
	int i, bool1, last_return = 0, line_number = 1;

	(void)argc;
	while (1)
	{
		bool1 = 0;
		if (isatty(STDIN_FILENO))
			printf("$ ");
		if (getline(&line, &linesize, stdin) == -1)
			break;
		newline_index = _strcspn(line, "\n");
		if (line[newline_index] == '\n')
			line[newline_index] = '\0';

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

/**
 * end_of_file - Handles the end of file (EOF) and executes commands.
 *
 * @line: The input line read from stdin.
 * @argv: The argument vector for the command.
 * @line_number: The current line number.
 *
 * Return: 1 if the command is executed successfully, otherwise the result of
 *         executing the command.
 */
int end_of_file(char *line, char **argv, int *line_number)
{
	const char *delimiter = " ";
	builtin_t builtins[] = {{"env", env_command},
	{"exit", exit_command}, {NULL, NULL}};
	int i, result = 0;

	if (!isatty(STDIN_FILENO))
	{
		free(line);
		exit(0);
	}
	if (line == NULL || *line == '\0')
	{
		write(STDOUT_FILENO, "\n", 1);
		free(line);
		return (1);
	}

	for (i = 0; builtins[i].name != NULL; i++)
	{
		if (_strcmp(builtins[i].name, line) == 0)
		{
			builtins[i].func(line);
			free(line);
			return (1);
		}
	}

	result = execute_command(line, delimiter, argv[0], *line_number);
	(*line_number)++;
	free(line);
	return (result);
}


