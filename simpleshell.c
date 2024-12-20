#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{

	char *line;
        size_t linesize = 65;
	const char *delimiter =  " ";
        char *argv[100];
	int i = 0;
	pid_t pid;
	int len;
	char *env_args[] = {"PATH", NULL};
	int status;

	while(1)
	{
		printf("HMShell:~$");
        	line = (char *)malloc(linesize * sizeof(char));
        	if (line == NULL)
        	{
                	perror("Unable to allocate buffer");
                	exit(1);
        	}

        	getline(&line,&linesize,stdin);
		for (len = 0; line[len] != '\n'; len++);
		line[len++] = '\0';

		if (strcmp(line, "exit") == 0)
                {
			free(line);
                        exit(99);
                }

		argv[0] = strtok(line, delimiter);

        	for (i = 1; argv[i] != NULL; ++i)
        	{
                	argv[i] = strtok(NULL, delimiter);
        	}
		argv[i] = NULL;
		pid = fork();
		if (pid == -1)
    		{
        		perror("Error:");
        		return (1);
			exit (1);
    		}
		if (pid == 0)
    		{
        		if (execve(argv[0], argv, env_args) == -1)
			{
				perror("Commande non existante");
				exit(1);
			}
    		}
		else
		{
			wait(&status);
		}
		free (line);
	}
	return(0);
}
