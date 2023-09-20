#include "shell.h"
/**
* _strcpy - checks if charcter is an alphabet
* @dest : pointer argument
* @src : pointer argument
* Return: 1 if alphabet and 0 otherwise
*/
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i++] = '\0';
	return (dest);
}

/**
* _strcmp - check if charcter is an alphabet
* @s1 : pointer argument
* @s2 : pointer argument
* Return: 1 if alphabet and 0 otherwise
*/
int _strcmp(char *s1, char *s2)
{
	int i, counter;

	counter = 0;
	for (i = 0; s1[i] != '\0' || s2[i] != '\0'; i++)
	{
		if (s1[i] == s2[i])
		{
			if (s1[i] == '\0' && s2[i] == '\0')
				break;

			continue;
		}

		if (s1[i] != s2[i])
		{
			counter = s1[i] - s2[i];
			break;
		}
	}
	return (counter);
}

/**
* _strlen - check if charcter is an alphabet
* @s : pointer argument
* Return: 1 if alphabet and 0 otherwise
*/
int _strlen(char *s)
{
	char com, *h;
	int counter;

	counter = 0;
	h = s;
	com = *h;
	while (1)
	{
		if (com == '\0')
			break;

		counter += 1;
		h += 1;
		com = *h;
	}
	return (counter);
}


/**
* _strdup - check if charcter is an alphabet
* @str : pointer argument
* Return: 1 if alphabet and 0 otherwise
*/
char *_strdup(char *str)
{
	char *ptr;
	int i, x;

	if (str == NULL)
		return (NULL);

	x = _strlen(str);
	ptr = malloc(x * sizeof(char) + 1);
	if (ptr == NULL)
		return (NULL);

	for (i = 0; i < x; i++)
	{
		ptr[i] = str[i];
	}
	ptr[i] = '\0';
	return (ptr);
}


/**
* _strcat - check if charcter is an alphabet
* @dest : pointer argument
* @src : pointer argument
* Return: 1 if alphabet and 0 otherwise
*/
char *_strcat(char *dest, char *src)
{
	int i, j;

	j = 0;
	for (i = _strlen(dest); src[j] != '\0'; i++)
	{
		dest[i] = src[j];
		j += 1;
	}
	dest[i] = '\0';
	return (dest);
}
