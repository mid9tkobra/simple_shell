#include "shell.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
void argsmod(char *buf)
{
	char *buf2;
	struct stat *st;

	buf2 = malloc(sizeof(char) * 1024);
	strcpy(buf2, getenv("PWD"));
	strcat(buf2, buf);
	if (stat(buf2, st) == 0)
	{
		strcpy(buf, buf2);
	}
	return;	
}
