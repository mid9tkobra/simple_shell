#include "shell.h"
void exo(char *buf, char **args, int y, char **env)
{
	pid_t child;
	int st;
 
	child = fork();
		if (child == 0)
		{
			if (y == 3)
			{
				chdir(args[1]);
			}
			else
			{
				execve(buf, args, env);
			}
		}
		else
		{
			wait(&st);
			free(buf);
		}
}
void interactive(char *buf, char **args, char **env, char *av0)
{
	int status, j, argcou, y, in = 0, re = 0, cou = 0;
	size_t i;
	ssize_t x;
	pid_t child;
	char buf3[1024], buf4[1024], *buf7;

	while (1)
	{
		buf = malloc(sizeof(char) * 1024);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		x = getline(&buf, &i, stdin);
		while (buf[in] != '\0' && buf[in] != EOF)
		{
			if (buf[in] != ' ' && buf[in] != '	')
				re = 1;
			in++;
		}
		in = 0;
		if (!re)
			x = -1;
		re = 0;
		stdin->_flags &= ~-1;
		if (x == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return;
		}
		argcou = argcount(buf);
		strcpy(buf3, buf);
		args = malloc((argcou + 1) * sizeof(char *));
		strtok(buf, " \t\n");
		y = _check(buf);
		if (!y)
		{
			free(args);
			errhand(0, av0, buf, &cou);
			continue;
		}
		strtok(buf3, " \t\n");
		args[0] = malloc(sizeof(char) * (strlen(buf3) + 1));
		strcpy(args[0], buf3);
		for (j = 1; j < argcou; j++)
		{
			strcpy(buf4, strtok(NULL, " \t\n"));
			args[j] = malloc(sizeof(char) * (strlen(buf4) + 1));
			strcpy(args[j], buf4);
			buf7 = args[j];
			argsmod(buf7);
		}
		args[j] = NULL;
		exo(buf, args, y, env);
	}
}
int main(int ac, char **av, char **env)
{
	pid_t parent;
	int i = 0, j = 1;
	char *buf, **args;

	interactive(buf, args, env, av[0]);
	return (0);
}
