/* main.h */

#ifndef __MAIN__
#define __MAIN__

#include <stdlib.h>
#include <locale.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <libintl.h>
#include <errno.h>

#define ENABLE_NLS 1
#define _(s) gettext (s)

#endif /* __MAIN__ */

#ifdef HAVE_CONFIG_H
	#include <config.h>
#endif

#ifndef DEFAULT_PASSWORD_LENGTH
	#define DEFAULT_PASSWORD_LENGTH 25
#endif
