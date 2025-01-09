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
 * @nom_shell: constant name of shell sent from main
 * @line_number: count the number of line since the beginning
 * of executable shell
 * Return: The exit status of the command
 */
int execute_program(char *command, char **argv,
const char *nom_shell, int *line_number)
{

	pid_t pid;
	int status;
	/*char *name = "./shell";*/

	if (handle_lign(command) == 1)
	{
		fprintf(stderr, "%s: %d: %s: Permission denied\n",
		nom_shell, *line_number, command);
		return (127);
	}
	pid = fork();
	if (pid == -1)
	{
		fprintf(stderr, "Error:");
		exit(1);
	}
	if (pid == 0)
	{
		if (execve(command, argv, environ) == -1)
		{
			fprintf(stderr, "%s: %d: %s: Permission denied\n",
			nom_shell, *line_number, command);
			return (127);
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
	fprintf(stderr, "%s: %d: %s: not found\n",
	shell_name, line_number, command);
	last_return = 127;
	return (last_return);
}

/**
 * is_more_than1 - Check if the command contains more than one character,
 *                 and remove quotes (both single and double) if present.
 *
 * @command: A pointer to the string (command) to be checked and processed.
 *
 * Return:
 * - 0: If the string is empty or contains only a single character,
 *       or if no quotes are
 *	 found in the string.
 * - 1: If the string contains more than
 *      one character (excluding quotes).
 */
int is_more_than1(char *command)
{
	int i;

	if (command == NULL || *command == '\0')
		return (0);
	for (i = 0; command[i] != '\0'; i++)
	{
		if (command[i] == '"' || command[i] == '\'')
		{
			command[i] = ' ';
		}
		if (command[i] == '\\' || command[i] == '`')
		{
			command[i] = ' ';
		}
		if (command[i] == '*' || command[i] == '&')
		{
			command[i] = ' ';
		}
		if (command[i] == '#')
		{
			command[i] = ' ';
		}
	}
	return (0);
}
/**
 * handle_lign - Verifie si une chaine de caracteres
 * contient uniquement des '/'.
 * @command: La commande à analyser.
 *
 * Return: 1 si la commande est uniquement composée de '/'.
 *         0 si la commande contient un autre caractère que '/'.
 */
int handle_lign(char *command)
{
	int i;

	for (i = 0; command[i] != '\0'; i++)
	{
		if (command[i] != '/')
		{
			return (0);
		}
	}
return (1);
}
