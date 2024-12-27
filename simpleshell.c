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
    char *line = NULL;
    const char *delimiter = " ";
    printf("\033[H\033[J");
    while (1)
    {
        printf("HMShell:~$ ");
        //line = (char *)malloc(linesize * sizeof(char));
        if (getline(&line, &linesize, stdin) == -1)
        {
            break;
        }
	line[strcspn(line, "\n")] = '\0';

	if (couleur(line) == 0)
		continue;
        exit_command(line);
	execute_command(line, delimiter);
    }
    return (0);
}
