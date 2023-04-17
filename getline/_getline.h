#ifndef getline_h
#define getline_h
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024

char *_getline(const int fd);

#endif
