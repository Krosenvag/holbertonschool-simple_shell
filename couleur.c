#include "main.h"
#include <string.h>
#include <stdio.h>

int couleur(char *line)
{
	int b = 1, j;

	for (j = 0; line[j] != '\n'; j++);
        line[j++] = '\0';
	if (_strcmp(line, "green\n") == 0 || _strcmp(line, "green") == 0)
	{
		printf("\033[0;32m");  // Texte en vert
		printf("Color changed to green ! \n");
		b = 0;
	}
	else if (_strcmp(line, "red\n") == 0 || _strcmp(line, "red") == 0)
	{
		printf("\033[0;31m");  // Texte en rouge
		printf("Color changed to red !\n");
		b = 0;
	}
	else if (_strcmp(line, "blue\n") == 0 || _strcmp(line, "blue") == 0)
	{
		printf("\033[0;34m");  // Texte en bleu
		printf("Color changed to blue ! \n");
		b = 0;
	}
	else if (_strcmp(line, "white\n") == 0 || _strcmp(line, "white") == 0)
	{
	printf("\033[0m");  // Réinitialiser la couleur par défaut
	b = 0;
	printf("Color changed to white ! \n");
	}
	else if (_strcmp(line, "purple\n") == 0 || _strcmp(line, "purple") == 0)
	{
		printf("\033[0;35m");
		b = 0;
		printf("Color changed to purple ! \n");
	}
	return (b);
}
