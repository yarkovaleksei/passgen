#include <getopt.h>
#include <unistd.h>
#include <time.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *genpass(char*, int);

int getopt_long(int argc, char * const argv[], const char *optstring, const struct option *longopts, int *longindex);

extern char *optarg;
extern int optind, opterr, optopt;
