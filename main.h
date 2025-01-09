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
	void (*func)(char *line, int number);
} builtin_t;

int handle_error(const char *shell_name, const char *command,
int line_number, int last_return);
int execute_program(char *command, char **argv,
const char *nom_shell, int *line_number);
char *find_command(const char *command);
void exit_command(char *command, int number);
int execute_command(char *line, const char *delimiter,
const char *nom_shell, int line_number);
int couleur(char *line);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strdup(const char *str);
void free_grid(char **grid);
char *_strstr(char *haystack, char *needle);
void env_command(char *string, int number);
void read1(void);
char *get_env(char *name);
void is_isatty(char *line, const char *delimiter);
void print_which(char **argv, char *argv0);
int end_of_file(char *line, int *eof_count);
size_t _strcspn(const char *s, const char *reject);
int _strlen(char *s);
int control_d(char *str);
int is_special_char(char *command);
int handle_lign(char *command);
int handle_point(char *command);
void free_chemin(char *chemin, char *copie_chemin);
#endif
