#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H
#include <stdio.h>
#include <unistd.h>
void do_nothing(char *s);

#ifdef _WIN32
size_t getline(char **lineptr, size_t *n, FILE *stream);
unsigned int getppid(void);
#endif

#endif
