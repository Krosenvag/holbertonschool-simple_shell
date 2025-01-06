#include "main.h"

/**
print_env - print enviroment
*/


void env_command(char *string)
{
	int i;
	extern char **environ;

	if (!environ)
		return;

	for (i = 0; environ[i]; i++)
	{
		printf("%s\n", environ[i]);
	}
}
