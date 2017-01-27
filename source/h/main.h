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

#define PATTERN_UP "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define PATTERN_DOWN "abcdefghijklmnopqrstuvwxyz"
#define PATTERN_NUMBER "0123456789"
#define PATTERN_SYMBOL "!@#$%^&*()_+=-.,/`\\[]{}|"

#endif /* __MAIN__ */

#ifdef HAVE_CONFIG_H
	#include <config.h>
#else
	#define PACKAGE_VERSION "1.0.0"
	#define PACKAGE_AUTHOR "Yarkov Aleksey"
	#define PACKAGE_BUGREPORT "yarkov_aleksei@mail.ru"
	#define PACKAGE_DESCRIPTION "Console password generator"
	#define PACKAGE_LICENSE "MIT"
	#define PACKAGE_NAME "passgen"
	#define PACKAGE_STRING "passgen 1.0.0"
	#define PACKAGE_TARNAME "passgen_v1.0.0"
	#define PACKAGE_URL "https://github.com/yarkovaleksei/passgen"
#endif


/*#define DEFAULT_PASSWORD_LENGTH 25
#define MAX_PASSWORD_LENGTH 4096
#define MAX_PASSWORD_COUNT 1000000
#define MAX_PATTERN_LENGTH 200
#define ERROR_MSG_BUFFER_LENGTH 300*/
