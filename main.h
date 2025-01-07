#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdarg.h>
extern char **environ;
/**
 *	struct builtin - Structure associant une commande intégrée à sa fonction
 *	@name: Nom de la commande intégrée (ex. "cd", "exit")
 *	@func: Pointeur vers la fonction associée à la commande
 *
 *	Description: Cette structure permet de mapper une commande intégrée
 *	à la fonction correspondante pour son exécution.
 */
typedef struct builtin
{
	char *name;
	void (*func)(char *line);
} builtin_t;

/**
 *	struct color_map - Structure associant un nom à un code couleur
 *	@name: Nom associé à une couleur (ex. "red", "blue")
 *	@code: Code couleur correspondant (ex. "\033[0;31m" pour rouge)
 *	@message: Message utilisant le code couleur
 *
 *	Description: Cette structure permet de mapper un nom de couleur à son
 *	code ANSI correspondant et au message personnalisé utilisant cette couleur.
 */
typedef struct color_map
{
	char *name;
	char *code;
	char *message;
} color_map_t;
void handle_error(const char *nom_shell, const char *command, int *last_return);
int execute_program(char *command, char **argv);
char *find_command(const char *command);
void exit_command(char *command);
int execute_command(char *line, const char *delimiter, const char *nom_shell);
int couleur(char *line);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strdup(const char *str);
void free_grid(char **grid);
char *_strstr(char *haystack, char *needle);
void env_command(char *string);
void *read1(void);
size_t *_strcspn(char *str, char *str1);
char *get_env(char *name);
void is_isatty(char *line, const char *delimiter);
void print_which(char **argv, char *argv0);
#endif
