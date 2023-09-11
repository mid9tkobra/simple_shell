#include "shell.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stddef.h>
void exo()
{
	child = fork();
		if (child == 0)
		{
			if (y == 3)
			{
				chdir(args[1]);
			}
			else
			{
				chdir(buf6);
				free(buf6);
				execve(buf, args, env);
			}
		}
		else
		{
			wait(&status);
			chdir(buf5);
		}
}
void interactive(char *buf, char *buf2, char **args, char **env)
{
	int status, j, argcou, x, y;
	size_t i;
	pid_t child;
	char buf3[1024], buf4[1024], buf5[1024], *buf6, *buf7;

	while (1)
	{
		buf6 = malloc(sizeof(char) * 1024);
		strcpy(buf5, getenv("PWD"));
		write(STDOUT_FILENO, buf2, 2);
		x = read(STDIN_FILENO, buf, 1024);
		if (x == 0)
			return;
		if (buf[(x - 1)] == '\n')
			buf[(x - 1)] = '\0';
		argcou = argcount(buf);
		strcpy(buf3, buf);
		args = malloc((argcou + 1) * sizeof(char *));
		strtok(buf, " ");
		y = _check(buf, buf6);
		if (!y)
		{
			free(args);
			continue;
		}
		args[0] = malloc(sizeof(char) * (strlen(buf) + 1));
		strcpy(args[0], buf);
		strtok(buf3, " ");
		for (j = 1; j < argcou; j++)
		{
			strcpy(buf4, strtok(NULL, " "));
			args[j] = malloc(sizeof(char) * (strlen(buf4) + 1));
			strcpy(args[j], buf4);
			buf7 = args[j];
			argsmod(buf7);
		}
		args[j] = NULL;
	}
}
int main(int ac, char **av, char **env)
{
	pid_t parent;
	int i = 0, j = 1;
	char *buf, **args, *buf2 = "$ ";

	parent = getpid();
	buf = malloc(sizeof(char) * 1024);
	if (ac == 1)
	{
		interactive(buf, buf2, args, env);
	}
	/*else
	{

		args = malloc(sizeof(char *) * (ac - 1));
		while (av[j])
		{
			args[i] = av[j];
			i++;
			j++;
		}
		buf = args[0];
		execve(buf, args, env);
	}*/
	return (0);
}
