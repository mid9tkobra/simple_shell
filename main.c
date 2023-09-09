#include "shell.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stddef.h>
void interactive(char *buf, char *buf2, char **args)
{
	int status, j, argcou, x;
	size_t i;
	pid_t child;
	
	while (1)
		{
			write(STDOUT_FILENO, buf2, 2);
			x = read(STDIN_FILENO, buf, 1024);
			if (x == 0)
				return (0);
			if (buf[(x - 1)] == '\n')
				buf[(x - 1)] = '\0';
			argcou = argcount(buf);
			args = malloc(argcou * sizeof(char *));
			buf = strtok(buf, " ");
			args[0] = buf;
			for (j = 1; j < argcou; j++)
			{
				args[j] = strtok(NULL, " ");
			}
			(void)args;
			child = fork();
			if (child == -1)
			{
				perror("Error:\n");
				exit(1);
			}

			if (child == 0)
			{
				if (strcmp(buf, "cd") == 0)
					chdir(args[1]);
				else
					execve(buf, args, environ);
			}
			else
			{
				wait(&status);
			}
		}
}
int main (int ac, char **av, char **env)
{
	pid_t parent;
	int i = 0, j = 1;
	char *buf, **args, *buf2 = "$ ";
	extern char **environ;
	parent = getpid();
	buf = malloc(sizeof(char) * 1024);
	if (ac == 1)
	{
		interactive(buf, buf2, args);
	}
	else
	{
		args = malloc(sizeof(char *) * (ac - 1);
		while(av[j])
		{
			args[i] = av[j];
			i++;
			j++;
		}
		buf = args[0];
		execve(buf, args, environ);
	}
	return (0);
}
