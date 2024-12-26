#include "main.h"
#include <string.h>
#include <stdlib.h>

void *exit_command(char *command)
{
        command[strcspn(command, "\n")] = '\0';
        if (strcmp(command, "exit") == 0)
        {
            free(command);
            exit(99);
        }
	return (NULL);
}
