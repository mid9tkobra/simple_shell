#include "main.h"

/**
* print_number - print a number to stdout
*@n: the number to be printed
*@buffer : local buffer on printf
*@j : index of buffer
*@count : number of charcters printed
* Return: 1 if alphabet and 0 otherwise
*/
void print_number(int n, char *buffer, int *j, int *count)
{
	unsigned int n1;

	if (n < 0)
	{
		n1 = (unsigned int)-n;
		buffer[*j] = '-';
		(*j)++;
		(*count)++;
		if (*j == 1023)
			reset(buffer, j);
	}
	else
	{
		n1 = (unsigned int)n;
	}

	if (n1 / 10)
	{
		print_number(n1 / 10, buffer, j, count);
	}

	buffer[*j] = (n1 % 10 + '0');
	(*j)++;
	(*count)++;
	if (*j == 1023)
		reset(buffer, j);
}
