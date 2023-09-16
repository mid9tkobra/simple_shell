#ifndef SHELL_H
#define SHELL_H
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stddef.h>

int argcount(char *buf);
int _check(char *buf);
void argsmod(char *buf);
void print_number(int n, char *buffer, int *j);
void errhand(int n, char *buf, char *buf2, int *cou);
#endif
