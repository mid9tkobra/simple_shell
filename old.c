#include "shell.h"
/**
*cd1 - (handle cd -)
*Return: nothing
*/
void cd1(void)
{
	char *tmp = NULL, cwd[1024];

	tmp = _getenv("OLDPWD");
	if (tmp)
	{
		write(STDOUT_FILENO, tmp, _strlen(tmp));
		write(STDOUT_FILENO, "\n", 1);
		chdir(tmp);
	}
	else
	{
		getcwd(cwd, 1023);
		_strcat(cwd, "\n");
		write(STDOUT_FILENO, cwd, _strlen(cwd));
	}
	free(tmp);
}
