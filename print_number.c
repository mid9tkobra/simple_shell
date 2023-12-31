/**
* print_number - print a number to stdout
*@n: the number to be printed
*@buffer : local buffer on printf
*@j : index of the buffer
* Return: 1 if alphabet and 0 otherwise
*/
void print_number(int n, char *buffer, int *j)
{
	unsigned int n1;

	if (n < 0)
	{
		n1 = (unsigned int)-n;
		buffer[*j] = '-';
		(*j)++;
	}
	else
	{
		n1 = (unsigned int)n;
	}

	if (n1 / 10)
	{
		print_number(n1 / 10, buffer, j);
	}

	buffer[*j] = (n1 % 10 + '0');
	(*j)++;
}
