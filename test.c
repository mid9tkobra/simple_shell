#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
int main()
{
	char *ptr;

	ptr = getenv("PATH");
	printf("%s\n", ptr);
	return (0);
}