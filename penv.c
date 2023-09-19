#include "shell.h"
/**
*penv - print enviroment
*Return: nothing
*/

void penv(void)
{
	int i;
	char buf[3072];

	if (environ == NULL)
		return;
	for (i = 0; environ[i] != NULL; i++)
	{
		_strcpy(buf, environ[i]);
		_strcat(buf, "\n");
		write(STDOUT_FILENO, buf, _strlen(buf));
	}
}
