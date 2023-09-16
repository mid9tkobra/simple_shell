#include "shell.h"
void errhand(int n, char *buf, char *buf2, int *cou)
{
	char *err;
	int ind = strlen(buf) + 2;

	err = malloc(sizeof(char) * 2048);
	switch (n)
	{
		case 0:
			(*cou)++;
			strcat(err, buf);
			strcat(err, ": ");
			print_number(*cou, err, &ind);
			strcat(err, ": ");
			strcat(err, buf2);
			strcat(err, ": ");
			strcat(err, "not found");
			strcat(err, "\n");
			write(STDOUT_FILENO, err, strlen(err));
			free(err);
	}
}
