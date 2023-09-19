#include "shell.h"
/**
*sup - support for _check
*@buf3 : buffer containing absolute path
*@re : pointer to buffer containing the absolute path
*@buf : executable name
*Return: status
*/
int sup(char **buf3, char **re, char *buf)
{
	char *tmp = NULL, buf2[2048];
	struct stat st;
	int i = 0, ch1, count = 0;

	tmp = _getenv("PATH");
	if (tmp)
	{
		_strcpy(buf2, tmp);
		free(tmp);
	}
	else
	{
		free(tmp);
		free(*buf3);
		*buf3 = NULL;
		return (0);
	}
	_strcat(buf2, ": ");
	while (buf2[i] != '\0')
	{
		if (buf2[i] == ':')
			count++;
		i++;
	}
	_strcpy(*buf3, strtok(buf2, ":"));
	while (count--)
	{
		_strcat((*buf3), "/");
		_strcat((*buf3), buf);
		ch1 = stat((*buf3), &st);
		if (ch1 == 0)
		{
			*re = *buf3;
			return (1);
		}
		_strcpy(*buf3, strtok(NULL, ":"));
	}
	free(*buf3);
	buf3 = NULL;
	return (0);
}
/**
*_check - check if executable available in path
*@buf : executable name
*@re : absolute path for exe
*Return: code for operatin to be done
*/
int _check(char *buf, char **re)
{
	char *buf3, *buf4 = "cd";
	char  ext[5] = "exit", envo[4] = "env";
	struct stat st;
	int ch2, ch3, count = 0;

	if (_strcmp(buf, envo) == 0)
		return (5);
	if (_strcmp(buf, ext) == 0)
		return (4);
	buf3 = malloc(sizeof(char) * 1024);
	ch3 = _strcmp(buf, buf4);
	if (ch3 == 0)
	{
		_strcpy(buf3, buf);
		*re = buf3;
		return (3);
	}
	if (buf[0] == '.' || buf[0] == '/')
	{
		ch2 = stat(buf, &st);
		if (ch2 == 0)
		{
			_strcpy(buf3, buf);
			*re = buf3;
			return (2);
		}
	}
	return (sup(&buf3, re, buf));
}
