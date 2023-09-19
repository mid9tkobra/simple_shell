#include "shell.h"
/**
*args_ar - creat an array of arguments
*@argcou : number  of arguments
*@buf : buffer containing arguments
*@args : array to allocate memory to
*Return: 0 on failuer 1 on success
*/
int args_ar(int argcou, char **buf, char ***args)
{
	char *buf7 = NULL, buf4[2048];
	int j;

	*args = malloc((argcou + 1) * sizeof(char *));
	if (*buf == NULL || strtok(*buf, " \t\n") == NULL)
	{
		free(*args);
		*args = NULL;
		free(*buf);
		*buf = NULL;
		return (0);
	}
	(*args)[0] = malloc(sizeof(char) * (_strlen(*buf) + 1));
	_strcpy((*args)[0], *buf);
	for (j = 1; j < argcou; j++)
	{
		_strcpy(buf4, strtok(NULL, " \t\n"));
		(*args)[j] = malloc(sizeof(char) * (_strlen(buf4) + 1));
		_strcpy((*args)[j], buf4);
	}
	(*args)[j] = NULL;
	return (1);
}
