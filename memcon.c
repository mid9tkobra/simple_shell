#include "shell.h"
/**
*free_ar - free 2D array
*@arr : array to be freed
*Return: nothing
*/

void free_ar(char **arr)
{
	int i;

	if (!arr)
		return;
	for (i = 0; arr[i] != NULL; i++)
	{
		free(arr[i]);
		arr[i] = NULL;
	}

	free(arr);
	arr = NULL;
}
