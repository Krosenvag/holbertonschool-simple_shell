#include "main.h"

/**
 * _strstr - Locates a substring
 * @haystack: First string
 * @needle: Substring
 * Return: Pointer to substring or NULL
*/

char *_strstr(char *haystack, char *needle)
{
	int i;

	for (i = 0 ; haystack[i] != '\0' ; i++)
	{
		if (needle[0] == '\0')
		{
			return (&haystack[0]);
		}

			else if (haystack[i] == needle[0] && haystack[i + 1] == needle[1])
			{
				return (&haystack[i]);
			}
	}

	return (NULL);
}
/**
 * get_env - search env por specific line
 * @name: word to look for in env
 * Return: return NULL if failed or pointer to path
 */
char *get_env(char *name)
{
	int i;
	char *token = NULL, *token_cpy = NULL, *buff = NULL;

	if (!environ)
		return (NULL);
	for (i = 0; environ[i]; i++)
	{
		buff = _strdup(environ[i]);
		token = strtok(buff, "=");
		if (_strcmp(token, name) == 0)
		{
			token = strtok(NULL, "=");
			if (token)
			{
				token_cpy = _strdup(token);
				free(buff);
				return (token_cpy);
			}
			free(buff);
		}
		free(buff);
	}
	return (NULL);
}
/**
 * _strcspn - Calculates the length of the initial segment of string `s`
 *           that does not contain any characters from string `reject`.
 *
 * @s: The input string to be searched.
 * @reject: The string containing the characters to be excluded.
 *
 * Return: The length of the initial segment of `s` that does not contain
 *         any characters from `reject`. If no such segment exists,
 *         returns the length of the string `s`.
 */
size_t _strcspn(const char *s, const char *reject)
{
	size_t i, j;

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; reject[j] != '\0'; j++)
		{
			if (s[i] == reject[j])
			{
				return (i);
			}
		}
	}
	return (i);
}

