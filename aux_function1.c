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

