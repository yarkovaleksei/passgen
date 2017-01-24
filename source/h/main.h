/* main.h */

#ifndef __MAIN__
#define __MAIN__

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

#endif /* __MAIN__ */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#ifdef HAVE_LIBLIBCRYPT
	#include <crypt.h>
#else
	#error Please install libcrypt-dev before compilation!
#endif
