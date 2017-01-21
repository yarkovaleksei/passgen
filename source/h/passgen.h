#include <locale.h>
#include <getopt.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <libintl.h>           /* заголовки функций gettext */

#define ENABLE_NLS 1           /* включаем поддержку nls */
#define _(s) gettext (s)       /* макрос для gettext */

#define VERSION "0.0.1"
#define PACKAGE "passgen"
#define LOCALEDIR "locale"


char *genpass(char*, int);
char getChar(char*);

int getopt_long(int argc, char * const argv[], const char *optstring, const struct option *longopts, int *longindex);

extern char *optarg;
extern int optind, opterr, optopt;
