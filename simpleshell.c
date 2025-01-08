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
			printf("($) ");
		if (getline(&line, &linesize, stdin) == -1)
			control_d(line);
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
			line = NULL;
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
 * control_d - Handles the EOF (Ctrl+D) signal in the shell.
 * @line: The pointer to the input buffer to be freed before exiting.
 *
 * Description:
 * This function is called when the user sends an EOF signal (Ctrl+D)
 * to the shell. It prints a newline, frees the memory allocated for
 * the input buffer, and gracefully exits the program with a status of 0.
 *
 * Return: This function does not return as it exits the program.
 */
void control_d(char *line)
{
	printf("\n");
	free(line);
	exit(0);
}
