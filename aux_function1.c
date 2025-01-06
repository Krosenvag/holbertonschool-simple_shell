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
 * couleur - Changes the terminal text color based on input.
 * @line: The input string specifying the desired color.
 *
 * Description: This function changes the terminal text color if the input
 * matches a predefined color. Supported colors are green, red, blue,
 * white, and purple.
 *
 * Return: 0 if the color was changed successfully, 1 otherwise.
 */
int couleur(char *line)
{
	int b = 1, j;

	color_map_t colors[] = {
		{"green", "\033[0;32m", "Color changed to green!"},
		{"red", "\033[0;31m", "Color changed to red!"},
		{"blue", "\033[0;34m", "Color changed to blue!"},
		{"white", "\033[0m", "Color changed to white!"},
		{"purple", "\033[0;35m", "Color changed to purple!"},
		{NULL, NULL, NULL}
	};

	for (j = 0; line[j] != '\n'; j++)
		;
	line[j] = '\0';

	for (int i = 0; colors[i].name; i++)
	{
		if (_strcmp(line, colors[i].name) == 0)
		{
			printf("%s", colors[i].code);
			printf("%s\n", colors[i].message);
			b = 0;
			break;
		}
	}

	return (b);
}
