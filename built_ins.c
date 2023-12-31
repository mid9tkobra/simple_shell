#include "shell.h"
/**
*sup_free - free buffer and arguments
*@args: argument list
*@buf: buffer
*Return: nothing
*/
void sup_free(char ***args, char **buf)
{
	free_ar(*args);
	*args = NULL;
	free(*buf);
	*buf = NULL;
}
/**
*set_unset - set or unset var
*@args: arguments list
*@st: exit status
*@n: code for operation
*@buf : buffer
*Return: nothing
*/
int set_unset(char ***args, int *st, int n, char **buf)
{
	if (n == 6)
	{
		if ((*args)[1] && (*args)[2])
		{
			if (setenv((*args)[1], (*args)[2], 1) == -1)
			{
				write(STDERR_FILENO, "can't set var", 14);
				*st = 127;
			}
			else
			{
				*st = 0;
			}
		}
		sup_free(args, buf);
		return (1);
	}
	else if (n == 7)
	{
		if ((*args)[1])
		{
			if (unsetenv((*args)[1]) == -1)
			{
				write(STDERR_FILENO, "can't unset var", 16);
				*st = 127;
			}
			else
			{
				*st = 0;
			}
		}
		sup_free(args, buf);
		return (1);
	}
	return (0);
}
/**
*_chdir - change working directory
*@dir: directory to change to
*@av0 : no need
*@cou : error count
*@st: exit status
*Return: nothing
*/
void _chdir(char *dir, char *av0, int *cou, int *st)
{
	char cwd[1024], old[1024];

	if (!dir)
	{
		dir = _getenv("HOME");
		getcwd(old, 1023);
		setenv("OLDPWD", old, 1);
		if (dir)
			chdir(dir);
		getcwd(cwd, 1023);
		setenv("PWD", cwd, 1);
		free(dir);
		return;
	}
	if (strcmp(dir, "-") == 0)
	{
		cd1();
		return;
	}
	getcwd(old, 1023);
	if (chdir(dir) == -1)
	{
		errhand(1, av0, dir, cou);
		*st = 127;
	}
	else
	{
		setenv("OLDPWD", old, 1);
		getcwd(cwd, 1023);
		setenv("PWD", cwd, 1);
		*st = 0;
	}
}
/**
*built - local shell built ins
*@y : status of input
*@args : arguments
*@buf : buffer containing command
*@st : status of exe
*@cou : error count
*@av0: no need to define
*Return: code for upcoming operation
*/
int built(int y, char ***args, char **buf, int *st, int *cou, char *av0)
{
	char buf3[1024];
	int go;

	switch (y)
	{
		case 0:
			errhand(0, av0, (*args)[0], cou);
			sup_free(args, buf);
			*st = 127;
			return (26);
		case 3:
			_chdir((*args)[1], av0, cou, st);
			sup_free(args, buf);
			return (26);
		case 4:
			if ((*args)[1])
			{
				_strcpy(buf3, (*args)[1]);
				go = 1;
			}
			else
			{
				go = 0;
			}
			sup_free(args, buf);
			if (go)
				exat(st, av0, buf3, cou);
			else
				exat(st, av0, NULL, cou);
			return (26);
		case 5:
			penv();
			sup_free(args, buf);
			*st = 0;
			return (26);
	}
	if (set_unset(args, st, y, buf))
		return (26);
	return (-1);
}
/**
*exat - exit shell
*@st: exit status
*@av0: no need
*@buf2: argument
*@cou: error count
*Return: nothing
*/
void exat(int *st, char *av0, char *buf2, int *cou)
{
	char err[1024];
	int ex_val = *st, i, x;

	if (buf2)
	{
		if (_isdigit(buf2))
		{
			ex_val = _atoi(buf2);
		}
		else
		{
			for (i = 0; i < 1024; i++)
				err[i] = 0;
			_strcat(err, av0);
			_strcat(err, ": ");
			x = _strlen(err);
			print_number(*cou, err, &x);
			_strcat(err, ": ");
			_strcat(err, "exit");
			_strcat(err, ": ");
			_strcat(err, "Illegal number");
			_strcat(err, ": ");
			_strcat(err, buf2);
			_strcat(err, "\n");
			write(STDERR_FILENO, err, _strlen(err));
			(*cou)++;
			*st = 2;
			return;
		}
	}
	exit(ex_val);
}
