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
		execve(command, argv, environ);
		perror("execve");
		exit(1);
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
		else
			return (1);
	}
}

/**
 * handle_error - Displays an error message for invalid commands
 * @nom_shell: Name of the shell for error messages
 * @command: Command that caused the error
 * @last_return: Pointer to the return value to update
 */
void handle_error(const char *nom_shell, const char *command, int *last_return)
{
	printf("%s: 1: %s: not found\n", nom_shell, command);
	*last_return = 127;
}
