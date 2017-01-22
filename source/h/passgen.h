#include <stdlib.h>
#include <locale.h>
#include <getopt.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <libintl.h> /* gettext */

#define ENABLE_NLS 1
#define _(s) gettext (s)

#define VERSION "0.0.1"
#define PACKAGE "passgen"
#define LOCALEDIR "locale"


/* Source: source/passgen.c */
struct passgen {
	char* (*getPassword)(char*, int);
	char (*getChar)(char*);
};
extern const struct passgen PassGen;

/* Source: <getopt.h> */
int getopt_long(int argc, char * const argv[], const char *optstring, const struct option *longopts, int *longindex);
extern char *optarg;
extern int optind, opterr, optopt;
