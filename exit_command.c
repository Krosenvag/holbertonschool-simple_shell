#include "main.h"
#include <string.h>
#include <stdlib.h>

void *exit_command(char *command)
{
        if (strcmp(command, "exit") == 0)
        {
            free(command);
            exit(99);
        }
	return (NULL);
}
