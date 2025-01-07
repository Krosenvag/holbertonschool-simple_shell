#include "main.h"

/**
 * _strcat - concatenate a string
 * @dest: stores a string
 * @src: stores a string
 * Return: pointer to string dest
 **/

char *_strcat(char *dest, char *src)
{
	char *dest_aux;
	const char *src_aux;

	dest_aux = dest;
	src_aux =  src;

	while (*dest_aux != '\0')
		dest_aux++;

	while (*src_aux != '\0')
		*dest_aux++ = *src_aux++;
	*dest_aux = '\0';
	return (dest);
}

/**
 * _strcmp - concatenate a string
 * @s1: pointer of a string
 * @s2: pointers of a string
 * Return: pointer to string dest
 **/

int _strcmp(char *s1, char *s2)
{

	int i;

	for (i = 0; s2[i] == s1[i] && s1[i] != '\0'; i++)
	{
	}
	if (s1[i] != s2[i])
	{
		return ((s1[i] - s2[i]));
	}
	else
	{
		return (0);
	}
}

/**
 * *_strcpy - copy the string to a buffer
 * @dest: pointer
 * @src: pointer
 * Return: 0
 **/


char *_strcpy(char *dest, char *src)
{
	int r = 0;

	for (; src[r] != '\0'; r++)
	{
		dest[r] = src[r];
	}

	dest[r] = '\0';

	return (dest);
}

/**
 * _strdup - copy of the string given as a parameter
 * @str: string of char
 *
 * Description: The _strdup() function returns a pointer to a new string which
 * is a duplicate of the string str.
 * Returns NULL if str = NULL
 *
 * Return: a pointer to the duplicated string.
 */

char *_strdup(const char *str)
{
	int i, j;
	char *array;

	if (str == NULL)
		return (NULL);

	for (i = 0 ; str[i] != '\0' ; i++)
	{
	}

	array = malloc(sizeof(char) * (i + 1));

	if (array == NULL)
		return (NULL);

	for (j = 0 ; j <= i ; j++)
		array[j] = str[j];
	
	return (array);
}

/**
 * free_grid - Frees a 2 dimensional grid
 * @grid: Grid to be freed
*/

void free_grid(char **grid)
{
	int height = 0, i;

	if (!grid)
		return;

	for (i = 0; grid[i]; i++)
		height++;

	for (i = 0; i < height; i++)
		free(grid[i]);

	free(grid);

}
