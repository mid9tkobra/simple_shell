#include "shell.h"
int _check(char *buf, char **re)
{
	char buf2[1024], *buf3, *buf4 = "cd";
	struct stat st;
	int ch1, ch2, ch3, i = 0, count = 0;

	buf3 = malloc(sizeof(char) *1024);
	ch3 = _strcmp(buf, buf4);
	if (ch3 == 0)
	{
		_strcpy(buf3, buf);
		*re = buf3;
		return (3);
	}
	ch2 = stat(buf, &st);
	if (ch2 == 0)
	{
		_strcpy(buf3, buf);
		*re = buf3;
		return (2);
	}
	_strcpy(buf2, getenv("PATH"));
	_strcat(buf2, ": ");
	while (buf2[i] != '\0')
	{
		if (buf2[i] == ':')
			count++;
		i++;
	}
	_strcpy(buf3, strtok(buf2, ":"));
	while (--count)
	{
		_strcat(buf3, "/");
		_strcat(buf3, buf);
		ch1 = stat(buf3, &st);
		if (ch1 == 0)
		{
			*re = buf3;
			return (1);
		}
		_strcpy(buf3, strtok(NULL, ":"));
	}
	free(buf3);
	return (0);
}
