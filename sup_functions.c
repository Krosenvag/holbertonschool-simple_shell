#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
/**
 * execute_program - Executes a program in a child process
 * @command: Path to the executable
 * @argv: Array of arguments
 *
 * Return: The exit status of the command
 */
int execute_program(char *command, char **argv)
{

	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("Error:");
		exit(1);
	}
	if (pid == 0)
	{
		if (execve(command, argv, environ) == -1)
		{
			return (8);
		}
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
		else
			return (1);
	}
	return (1);
}

/**
 * handle_error - Displays an error message for invalid commands
 * @shell_name: Name of the shell for error message
 * @command: Command that caused the error
 * @last_return: Pointer to the return value to update
 * @line_number: contains the number of line since the beggining
 * Return: return error value of 127
 */
int handle_error(const char *shell_name, const char *command,
int line_number, int last_return)
{
	printf("%s: %d: %s: not found\n", shell_name, line_number, command);
	last_return = 127;
	return (last_return);
}
