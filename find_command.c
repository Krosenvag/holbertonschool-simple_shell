#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include "main.h"
#include <sys/stat.h>

char *find_command(const char *command)
{
	char *chemin = getenv("PATH");
	char *copie_chemin;
	struct stat st;
	char *chemin_entier;
	char *dir;

	if (command[0] == '/')
	{
		if (stat(command, &st) == 0)
		{
			return (strdup(command));
		}
		return (NULL);
	}
	if (chemin == NULL)
		return (NULL);
	copie_chemin = strdup(chemin);
	if (copie_chemin == NULL)
		return (NULL);
	dir = strtok(copie_chemin, ":");
	while (dir != NULL)
	{
		chemin_entier = malloc(strlen(dir) + strlen(command) + 2);
		if (chemin_entier == NULL)
		{
			free(copie_chemin);
			return (NULL);
		}
		sprintf(chemin_entier, "%s/%s", dir, command);
		if (stat(chemin_entier, &st) == 0)
		{
			free(copie_chemin);
			return (chemin_entier);
		}
		free(chemin_entier);
		dir = strtok(NULL, ":");
	}
	free(copie_chemin);
	return (NULL);
}
