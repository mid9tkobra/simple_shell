#include "shell.h"

/**
* _isdigit - check if charcter is an alphabet
* @buf: the number to be checked
* Return: 1 if alphabet and 0 otherwise
*/
int _isdigit(char *buf)
{
	int i = 0;

	while (buf[i])
	{
		if (buf[i] >= 48 && buf[i] <= 57)
		{
			i++;
			continue;
		}
		else
			return (0);
	}
	return (1);
}
