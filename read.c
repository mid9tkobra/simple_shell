#include "shell.h"
/**
*_read - get line from termenal or file
*@buf : buffer to store input
*Return: -1 on failure 0 on success
*/
ssize_t _read(char **buf)
{
	size_t i = 0;
	int in = 0, re = 0;
	ssize_t x = 0;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
	x = getline(buf, &i, stdin);
	while (x != -1 && *buf && (*buf)[in] != '\0')
	{
		if ((*buf)[in] != ' ' && (*buf)[in] != '\t')
			re = 1;
		in++;
	}
	if (!re)
		x = -1;
	return (x);
}
