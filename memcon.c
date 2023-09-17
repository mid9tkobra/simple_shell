#include "shell.h"
void free_ar(char **arr)
{
	int i;

	if(!arr)
		return;
	for (i = 0; arr[i] != NULL; i++)
	{
		free(arr[i]);
		arr[i] = NULL;
	}

	free(arr);
	arr = NULL;
}
