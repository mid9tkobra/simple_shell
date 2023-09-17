#include "shell.h"
void exo(char *buf, char **args, int y, char **env, int argcou)
{
	pid_t child;
	int st, i;
	char chd[1024];
 
	child = fork();
		if (child == 0)
		{
			if (y == 3)
			{
				_strcpy(chd, args[1]);
				free(buf);
				buf = NULL;
				free_ar(args);
				args = NULL;
				if (chdir(chd) == -1)
					exit(127);
			}
			else
			{
				if (execve(buf, args, env) == -1)
				{
					free(buf);
					buf = NULL;
					free_ar(args);
					args = NULL;
					exit(127);
				}
			}
		}
		else
		{
			wait(&st);
			free_ar(args);
			args = NULL;
			if (buf)
			{
				free(buf);
				buf = NULL;
			}
			
		}
}
int start(char **env, char *av0)
{
	int status, j, argcou, y, in = 0, re = 0, cou = 0, con = 0;
	size_t i = 0;
	ssize_t x = 0;
	pid_t child;
	char *buf = NULL, **args = NULL, *buf2 = NULL, buf4[1024], *buf7 = NULL;

	while (1)
	{
		con = 0;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		x = getline(&buf, &i, stdin);
		if (!buf)
			continue;
		while (buf && buf[in] != '\0')
		{
			if (buf[in] != ' ' && buf[in] != '\t')
				re = 1;
			/*if (buf[in] != ' ' && buf[in] != '\t' && buf[in] != '\n')
				con = 1;*/
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
			free(buf);
			buf = NULL;
			return (0);
		}
		/*if (!con)
			continue;*/
		argcou = argcount(buf);
		args = malloc((argcou + 1) * sizeof(char *));
		if (buf == NULL || strtok(buf, " \t\n") == NULL)
		{
			free(args);
			args = NULL;
			free(buf);
			buf = NULL;
			continue;
		}
		args[0] = malloc(sizeof(char) * (_strlen(buf) + 1));
		_strcpy(args[0], buf);
		for (j = 1; j < argcou; j++)
		{
			_strcpy(buf4, strtok(NULL, " \t\n"));
			args[j] = malloc(sizeof(char) * (_strlen(buf4) + 1));
			_strcpy(args[j], buf4);
		}
		args[j] = NULL;
		y = _check(args[0], &buf2);
		if (y == 0)
		{
			free_ar(args);
			errhand(0, av0, buf, &cou);
			free(buf);
			buf = NULL;
			continue;
		}
		free(buf);
		buf = NULL;
		exo(buf2, args, y, env, argcou);
	}
}
int main(int ac, char **av, char **env)
{
	int status = 0;

	status = start(env, av[0]);
	return (status);
}
