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

char *find_command(const char *command);
void *exit_command(char *command);
void *execute_command(char *line, const char *delimiter);
int couleur(char *line);
char *_strcat(char *dest, char *src)
int _strcmp(char *s1, char *s2)
char *_strcpy(char *dest, char *src)
char *_strdup(char *str)
void free_grid(char **grid)
char *_strstr(char *haystack, char *needle)
#endif
