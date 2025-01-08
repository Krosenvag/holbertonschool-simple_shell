#include "main.h"
#include <stdlib.h> /* Pour malloc et NULL */

/**
 * _strcat - concatenate a string
 * @dest: stores a string (must have enough space)
 * @src: stores a string
 * Return: pointer to string dest
 **/
char *_strcat(char *dest, char *src)
{
	char *dest_aux = dest;

	while (*dest_aux != '\0')
		dest_aux++;

	while (*src != '\0')
		*dest_aux++ = *src++;
	*dest_aux = '\0';

	return (dest);
}

/**
 * _strcmp - compare two strings
 * @s1: pointer to the first string
 * @s2: pointer to the second string
 * Return: difference between the first unmatched characters
 **/
int _strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * _strcpy - copy the string to a buffer
 * @dest: pointer to the destination buffer
 * @src: pointer to the source string
 * Return: pointer to dest
 **/
char *_strcpy(char *dest, char *src)
{
	char *dest_aux = dest;

	while (*src != '\0')
		*dest_aux++ = *src++;
	*dest_aux = '\0';

	return (dest);
}

/**
 * _strdup - duplicate a string
 * @str: string of char
 *
 * Description: The _strdup() function returns a pointer to a new string
 * which is a duplicate of the string str. Returns NULL if str = NULL.
 *
 * Return: a pointer to the duplicated string, or NULL on failure.
 **/
char *_strdup(const char *str)
{
	int i;
	char *array;

	if (str == NULL)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
		;

	array = malloc(sizeof(char) * (i + 1));
	if (array == NULL)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
		array[i] = str[i];
	array[i] = '\0';

	return (array);
}
