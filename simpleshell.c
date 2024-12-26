#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include <sys/stat.h>

int main(void)
{
    size_t linesize = 65;
    char *line;
    const char *delimiter = " ";
    printf("\033[H\033[J");
    while (1)
    {
        printf("HMShell:~$ ");
        line = (char *)malloc(linesize * sizeof(char));
        if (line == NULL)
        {
            perror("Unable to allocate buffer");
            exit(1);
        }
        if (getline(&line, &linesize, stdin) == -1)
        {
            free(line);
            break;
        }
	if(couleur(line) == 0)
		continue;
        exit_command(line);
        execute_command(line, delimiter);
        free(line);
    }
    return (0);
}
