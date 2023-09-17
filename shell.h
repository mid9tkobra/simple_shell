#ifndef SHELL_H
#define SHELL_H
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stddef.h>

int argcount(char *buf);
int _check(char *buf, char **re);
void argsmod(char *buf);
void print_number(int n, char *buffer, int *j);
void errhand(int n, char *buf, char *buf2, int *cou);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
void free_ar(char **arr);
#endif
