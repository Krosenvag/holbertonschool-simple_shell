#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

/**
 * execute_command - Execute a command line input.
 * @line: The input line containing the command.
 * @delimiter: The delimiter to tokenize the command line.
 *
 * Return: Void pointer (returns NULL in case of an error).
 */
void *execute_command(char *line, const char *delimiter)
{
	extern char **environ;
	char **argv;
	char *env_args, *token, *temp_line;
	pid_t pid;
	int i, status, j = 0;

	temp_line = _strdup(line);
	token = strtok(temp_line, delimiter);
	while( token != NULL)
	{
		j++;
		token = strtok(NULL, delimiter);
	}
	argv = malloc((j + 1) * sizeof(char *));
	if (argv == NULL)
		return NULL;
	argv[0] = strtok(line, delimiter);
	if (argv[0] == NULL)
		return (NULL);
	for (i = 1; i < j++  && (argv[i] = strtok(NULL, delimiter)) != NULL; i++);
	argv[i] = NULL;
	env_args = find_command(argv[0]);
	if (env_args != NULL)
	{
		pid = fork();
		if (pid == -1)
		{
			perror("Error:");
			exit(1);
		}
		if (pid == 0)
			execve(env_args, argv, environ);
		else
			wait(&status);
	}
	else
		printf("Error : command not found\n");
	free (argv);
	return (NULL);
}
