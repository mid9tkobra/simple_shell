#include "shell.h"
int argcount(char *buf)
{
	int i, count = 0;
	char *tmp = NULL, *buf2 = NULL;

	tmp = strdup(buf);
	buf2 = strtok(tmp, " \t\n");
	while (buf2)
	{
		count++;
		buf2 =  strtok(NULL, " \t\n");
	}
	free(tmp);
	return (count);
}
