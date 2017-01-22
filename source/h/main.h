#pragma once
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

#include "config.h"

#define ENABLE_NLS 1
#define _(s) gettext (s)

#define LOCALEDIR "locale"

#endif /* __MAIN__ */
