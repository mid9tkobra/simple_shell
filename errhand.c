#include "shell.h"
void errhand(int n, char *buf, char *buf2, int *cou)
{
	char *err = NULL, *buf3 = ": ";
	int ind = _strlen(buf) + 2, i;

	err = malloc(sizeof(char) * 2048);
	for (i = 0; i < 2048; i++)
		err[i] = 0;
	switch (n)
	{
		case 0:
			(*cou)++;
			_strcat(err, buf);
			_strcat(err, buf3);
			print_number(*cou, err, &ind);
			_strcat(err, buf3);
			_strcat(err, buf2);
			_strcat(err, buf3);
			_strcat(err, "not found");
			_strcat(err, "\n");
			write(STDOUT_FILENO, err, _strlen(err));
			free(err);
	}
}
