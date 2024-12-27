#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

void *execute_command(char *line, const char *delimiter)
{
	extern char **environ;
	char *argv[100], *env_args;
	pid_t pid;
	int i = 0, status;

	printf("Line: '%s'\n", line);  // Afficher la ligne brute
	argv[0] = strtok(line, delimiter);

	if (argv[0] == NULL)
	{
		return(0);
	}


	for (i = 1; i < 100 && (argv[i] = strtok(NULL, delimiter)) != NULL; i++);
	argv[i] = NULL;

    // Si trop de tokens, avertir
    if (strtok(NULL, delimiter) != NULL)
    {
        fprintf(stderr, "Warning: Too many tokens! Only the first 10 are considered.\n");
    }

    // Afficher les arguments extraits
    printf("Total tokens extracted: %d\n", i);

    pid = fork();
    if (pid == -1)
    {
        perror("Error:");
        exit(1);
    }
    env_args = find_command(argv[0]);
    if (pid == 0)
    {
        if (execve(env_args, argv, environ) == -1)
        {
            perror("Commande non existante");
            exit(1);
        }
    }
    else
          wait(&status);

     return (0);
}
