int argcount(char *buf)
{
	int i, count = 0;

	for (i = 0; buf[i] != '\0'; i++)
	{
		if (buf[i] != ' ')
		{
			count++;
			while (buf[i] != ' ' && buf[i + 1] != '\0')
				i++;
		}
		while (buf[i] == ' ' && buf[i + 1] == ' ')
			i++;
	}
	return (count);
}
