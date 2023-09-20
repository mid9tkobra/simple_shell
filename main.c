#include "shell.h"
/**
*spfl - remove heading space from input
*@buf : buffer containing input
*Return: nothing
*/
void spfl(char **buf)
{
	char *tmp = NULL;
	int i = 0, x = 0, f = 1;

	tmp = malloc(sizeof(char) * (_strlen(*buf) + 1));
	_strcpy(tmp, *buf);
	while (tmp[i] && (*buf)[x])
	{
		while ((tmp[i] == ' ' || tmp[i] == '\t') && f)
		{
			i++;
		}
		if (tmp[i] == '\0')
			break;
		f = 0;
		(*buf)[x] = tmp[i];
		i++;
		x++;
	}
	free(tmp);
	tmp = NULL;
}
/**
*exo - execute command in a child process
*@buf : buffer containing command
*@args : list of arguments
*@env : enviroment variables
*@sta : exit status of execution
*Return: nothing
*/
void exo(char **buf, char **args, char **env, int *sta)
{
	pid_t child;
	int st;

	child = fork();
	if (child == 0)
	{
		if (execve(*buf, args, env) == -1)
		{
			free(*buf);
			*buf = NULL;
			free_ar(args);
			args = NULL;
			exit(127);
		}
	}
	else
	{
		wait(&st);
		*sta = WEXITSTATUS(st);
		free_ar(args);
		args = NULL;
		if (*buf)
		{
			free(*buf);
			*buf = NULL;
		}

	}
}
/**
*start - main program loop
*@env : enviroment variables
*@av0 : no need for definition
*@st : exit status of last execution
*Return: exit status of execution
*/
int start(char **env, char *av0, int *st)
{
	int argcou, y, cou = 1, builtv = -1;
	ssize_t x = 0;
	char *buf = NULL, **args = NULL, *buf2 = NULL;

	while (1)
	{
		x = _read(&buf);
		stdin->_flags &= ~-1;
		if (x == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			free(buf);
			buf = NULL;
			return (*st);
		}
		argcou = argcount(buf);
		spfl(&buf);
		if (args_ar(argcou, &buf, &args) == 0)
			continue;
		y = _check(args[0], &buf2);
		free(buf);
		buf = NULL;
		builtv = built(y, &args, &buf2, st, &cou, av0);
		if (builtv == 26)
			continue;
		exo(&buf2, args, env, st);
	}
}
/**
*main - entry point
*@ac : argument count
*@av : argument vector
*@env : enviroment variables
*Return: 0 on seccess or error code on failure
*/
int main(int ac, char **av, char **env)
{
	int status = 0;

	(void)ac;
	status = start(env, av[0], &status);
	exit(status);
}
