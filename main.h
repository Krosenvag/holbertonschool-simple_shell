#ifndef MAIN_H
#define MAIN_H

char *find_command(const char *command);
void *exit_command(char *command);
void *execute_command(char *line, const char *delimiter);
int couleur(char *line);

#endif
