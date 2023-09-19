#include "shell.h"
/**
*built - local shell built ins
*@y : status of input
*@args : arguments
*@buf : buffer containig command
*@st : status of exe
*@cou : error count
*@av0: no need to define
*Return: code for upcoming operation
*/
int built(int y, char ***args, char **buf, int *st, int *cou, char *av0)
{
	char chd[2048];

	switch (y)
	{
		case 0:
			errhand(0, av0, (*args)[0], cou);
			free_ar(*args);
			*args = NULL;
			*st = 127;
			free(*buf);
			*buf = NULL;
			return (26);
		case 3:
			_strcpy(chd, (*args)[1]);
			free(*buf);
			*buf = NULL;
			free_ar(*args);
			*args = NULL;
			if (chdir(chd) == -1)
			{
				*st = 127;
				break;
			}
			*st = 0;
			return (26);
		case 4:
			free(*buf);
			*buf = NULL;
			free_ar(*args);
			return (*st);
		case 5:
			penv();
			*st = 0;
			free(*buf);
			*buf = NULL;
			free_ar(*args);
			*args = NULL;
			return (26);
	}
	return (-1);
}
