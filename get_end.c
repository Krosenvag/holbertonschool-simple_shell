#include "main.h"
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
