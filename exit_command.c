#include "main.h"
#include <string.h>
#include <stdlib.h>

void exit_command(char *command)
{
        if (_strcmp(command, "exit") == 0)
        {
            free(command);
            exit(1);
        }
}
