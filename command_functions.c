
#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

/**
 * execute_command - Executes a command line input.
 * @line: The input line containing the command.
 * @delimiter: The delimiter used to tokenize the command line.
 * @nom_shell: ok frr
 * @line_number: aaaaah variable
 * Description: This function tokenizes the input command line, determines
 * the command to execute, and creates a child process to execute the command.
 * It handles memory allocation for arguments, forks a new process, and waits
 * for its completion.
 *
 * Return: Void pointer (always NULL).
 */
int execute_command(char *line, const char *delimiter,
const char *nom_shell, int line_number)
{
	char *env_args, *token, *temp_line = _strdup(line), **argv;
	int i, j = 0, last_return = 0;

	for (j = 0, token = strtok(temp_line, delimiter); token != NULL; j++)
		token = strtok(NULL, delimiter);
	is_more_than1(line);
	argv = malloc((j + 1) * sizeof(char *));
	if (argv == NULL)
	{
		free(temp_line);
		return (0);
	}
	argv[0] = strtok(line, delimiter);
	if (argv[0] == NULL)
	{
		free(argv);
		free(temp_line);
		return (0);
	}
	for (i = 1; i < j && (argv[i] = strtok(NULL, delimiter)) != NULL; i++)
		;
	argv[i] = NULL;
	env_args = find_command(argv[0]);
	if (env_args != NULL)
	{
		last_return = execute_program(env_args, argv,
		 nom_shell, &line_number);
	}
	else
	{
		last_return = handle_error(nom_shell, argv[0],
		line_number, last_return);
	}
	free(env_args);
	free(argv);
	free(temp_line);
	return (last_return);
}

/**
 * env_command - Prints the environment variables.
 * @string: The input string (unused in this function).
 *
 * Description: This function iterates through the environment variables
 * and prints each one to the standard output. If the environment is
 * unavailable, the function exits without performing any operation.
 *
 * Return: Void.
 */
void env_command(char *string)
{
	int i;

	(void)string;

	if (!environ)
		return;

	for (i = 0; environ[i]; i++)
	{
		printf("%s\n", environ[i]);
	}
}
/**
 * exit_command - Handles the "exit" command for the shell.
 * @command: The command string to check.
 *
 * Description: This function checks if the provided `command` matches
 * the string "exit". If so, it exits the program with a status of 1.
 *
 * Return: Void.
 */
void exit_command(char *command)
{
	(void)command;
	free(command);
	exit(EXIT_SUCCESS);
}

/**
 * find_command - Searches for the full path of a command in the PATH.
 * @command: The name of the command to search for.
 *
 * Description: This function checks if a given command exists in the PATH
 * environment variable. If the command is an absolute path (starts with '/'),
 * it checks directly for its existence. Otherwise, it iterates through each
 * directory in PATH, constructing a full path, and checks if the
 * command exists.
 *
 * Return: A dynamically allocated string containing the full path to the
 * command if found, or NULL if the command is not found or an error occurs.
 */
char *find_command(const char *command)
{
	char *chemin = get_env("PATH"), *copie_chemin, *chemin_entier, *dir;
	struct stat st;

	if (chemin == NULL)
		return (NULL);
	if ((command[0] == '/' && stat(command, &st) == 0) ||
	(command[0] == '.' && command[1] == '/' && stat(command, &st) == 0))
	{
		free(chemin);
		return (_strdup(command));
	}
	copie_chemin = _strdup(chemin);
	if (copie_chemin == NULL)
	{
		free(chemin);
		return (NULL);
	}
	dir = strtok(copie_chemin, ":");
	while (dir)
	{
		chemin_entier = malloc(strlen(dir) + strlen(command) + 2);
		if (chemin_entier)
		{
			sprintf(chemin_entier, "%s/%s", dir, command);
			if (stat(chemin_entier, &st) == 0)
			{
				free(chemin);
				free(copie_chemin);
				return (chemin_entier);
			}
			free(chemin_entier);
		}
		dir = strtok(NULL, ":");
	}
	free(chemin);
	free(copie_chemin);
	return (NULL);
}


