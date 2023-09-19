#include "shell.h"
/**
*_getenv - get value of an enviroment variable
*@var : the env variable
*Return: a pointer to the value
*/

char *_getenv(char *var)
{
	int i;
	char *tmp = NULL, *key = NULL, *value = NULL, *re = NULL;

	if (environ == NULL)
		return (NULL);
	for (i = 0; environ[i]; i++)
	{
		tmp = _strdup(environ[i]);
		key = strtok(tmp, "=");
		if (!(_strcmp(var, key)))
		{
			value = strtok(NULL, "\0");
			re = _strdup(value);
			free(tmp);
			return (re);
		}
		free(tmp);
		tmp = NULL;
	}
	return (NULL);
}
