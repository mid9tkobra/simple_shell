#include "shell.h"
/**
* argcount - count args in a line
*@buf : lines
*Return: arguments count
*/
int argcount(char *buf)
{
	int i, count = 0;
	char *tmp = NULL, *buf2 = NULL, *buf3 = " \t\n";

	tmp = _strdup(buf);
	buf2 = strtok(tmp, buf3);
	while (buf2)
	{
		count++;
		buf2 =  strtok(NULL, buf3);
	}
	free(tmp);
	return (count);
}
