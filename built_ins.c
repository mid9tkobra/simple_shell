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
	char chd[2048], buf3[1024];
	int go;

	switch (y)
	{
		case 0:
			errhand(0, av0, (*args)[0], cou);
			sup_free(args, buf);
			*st = 127;
			return (26);
		case 3:
			_strcpy(chd, (*args)[1]);
			sup_free(args, buf);
			if (chdir(chd) == -1)
				*st = 127;
			*st = 0;
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
			*st = 2;
			return;
		}
	}
	exit(ex_val);
}
