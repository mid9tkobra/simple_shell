#include "shell.h"

/**
* _atoi - check if charcter is an alphabet
* @s : pointer argument
* Return: 1 if alphabet and 0 otherwise
*/
int _atoi(char *s)
{
	int i, sign;
	double new;

	sign = 0;
	new = 0;
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == 45)
			sign += 1;

		if (s[i] >= 48 && s[i] <= 57)
		{
			new = (new * 10) + (s[i] - 48);
		}
		if ((s[i] >= 48 && s[i] <= 57) && (s[i + 1] < 48 || s[i + 1] > 57))
		{
			break;
		}
	}
		if (sign % 2 != 0)
			new = -new;
		else
			new = new;

		return (new);
}
