/* arguments.c */


#include "h/arguments.h"


ARG_KEYS ArgKeys[] = {
	{"help", 			'h', 			"-h, --help", 				"-h[--help]", 				"description"},
	{"version", 		'v', 			"-v, --version", 			"-v[--version]", 			"description"},
	{"length", 			'l', 			"-l, --length=LENGTH", 		"-l[--length]", 			"description"},
	{"count", 			'c', 			"-c, --count=COUNT", 		"-c[--count]", 				"description"},
	{"pattern", 		'P', 			"-P, --pattern=PATTERN", 	"-P[--pattern]", 			"description"},
	{"letter-up", 		'u', 			"-u, --letter-up", 			"-u[--letter-up]", 			"description"},
	{"letter-down", 	'd', 			"-d, --letter-down", 		"-d[--letter-down]", 		"description"},
	{"number", 			'n', 			"-n, --number", 			"-n[--number]", 			"description"},
	{"symbol", 			's', 			"-s, --symbol", 			"-s[--symbol]", 			"description"},
	{"enable-space", 	'e', 			"-e, --enable-space", 		"-e[--enable-space]", 		"description"}
};
