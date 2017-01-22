/* print.c */

#include "h/main.h"
#include "h/print.h"


void help(int *length)
{
	printf("%s\n", _("Console password generator"));
	printf("\n");
	printf("%s:\n", _("Default values"));
	printf("\t%s:                 %d\n", _("Password length"), *length);
	printf("\n");
	printf("%s:\n", _("Usage keys"));
	printf("\t-h, --help                       %s\n", _("Help information"));
	printf("\t-v, --version                    %s\n", _("Package version"));
	printf("\t-l, --length                     %s\n", _("Password length. If not specified,"));
	printf("\t                                 %s\n", _("it will be set to 25. If set to 0,"));
	printf("\t                                 %s\n", _("the program will ask for input from the keyboard."));
	printf("\t-c, --count                      %s\n", _("The amount for one time passwords."));
	printf("\t                                 %s\n", _("It is useful when you need to create"));
	printf("\t                                 %s\n", _("a file with a unique string."));
	printf("\t-P, --pattern                    %s\n", _("A string containing the possible"));
	printf("\t                                 %s\n", _("characters in the password."));
	printf("\t                                 %s\n", _("If the key is specified, the keys"));
	printf("\t                                 -u, -d, -n, -s %s\n", _("will be ignored."));
	printf("\t-u, --letter-up                  %s\n", _("Use uppercase letters in the password"));
	printf("\t-d, --letter-down                %s\n", _("Use lowercase letters in the password"));
	printf("\t-n, --number                     %s\n", _("Use the numbers in the password"));
	printf("\t-s, --symbol                     %s\n", _("Use punctuation to the password"));
	printf("\t-e, --enable-space               %s\n", _("Add space to the password pattern"));
	printf("\n");
	printf("%s:\n", _("Example"));
	printf("\t$ %s -l0  -u                # %s\n", PACKAGE_NAME, _("Input length from the keyboard"));
	printf("\t$ %s -l25 -d                # %s\n", PACKAGE_NAME, _("Use the lowercase letters only"));
	printf("\t$ %s -l25 -s                # %s\n", PACKAGE_NAME, _("Use punctuation marks only"));
	printf("\t$ %s -l25 -dn               # %s\n", PACKAGE_NAME, _("Use lowercase letters and numbers only"));
	printf("\t$ %s -l25 -du               # %s\n", PACKAGE_NAME, _("Use lowercase and uppercase letters only"));
	printf("\t$ %s -l25 -P123abc          # %s\n", PACKAGE_NAME, _("Use symbols '123abc' only"));
	printf("\t$ %s -l25 -P123abc -e       # %s\n", PACKAGE_NAME, _("Use symbols '123abc' with space"));
	printf("\t$ %s -l25 -c5               # %s\n", PACKAGE_NAME, _("List of the 5 passwords, one per line"));
	exit(EXIT_SUCCESS);
}

void version()
{
	printf("%s\n", PACKAGE_VERSION);
	exit(EXIT_SUCCESS);
}

void echo(char * const msg, ...)
{
	va_list arguments;
	char *format = (char*)malloc((sizeof(PACKAGE_NAME) + sizeof(PACKAGE_VERSION) + sizeof(msg)) * sizeof(arguments));
	sprintf(format, "[%s-%s]: %s\n", PACKAGE_NAME, PACKAGE_VERSION, msg);
	va_start(arguments, msg);
	vprintf(format, arguments);
	va_end(arguments);
}


const struct print Print = {
	.help = help,
	.version = version,
	.echo = echo
};
