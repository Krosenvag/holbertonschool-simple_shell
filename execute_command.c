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

    argv[0] = strtok(line, delimiter);
    for (i = 1; argv[i] != NULL; ++i)
        argv[i] = strtok(NULL, delimiter);
    argv[i] = NULL;

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
        return (NULL);
}
