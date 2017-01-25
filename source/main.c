/* main.c */

#include "h/main.h"
#include "h/arguments.h"
#include "h/passgen.h"
#include "h/print.h"
#include "h/valid.h"


int main (int argc, char * const argv[], char * const argp[])
{
	srand((unsigned) time(NULL) * getpid());
	setlocale(LC_ALL, "");

	#ifdef PACKAGE_LOCALE_DIR
		bindtextdomain(PACKAGE_NAME, PACKAGE_LOCALE_DIR);
	#else
		#error Please use flag -DPACKAGE_LOCALE_DIR="path/to/locales/dir"!
	#endif

	textdomain(PACKAGE_NAME);

	int length = DEFAULT_PASSWORD_LENGTH;
	int count = 1;
	int usePattern = 0;
	char *password;
	char *LETTERS_UP = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *LETTERS_DOWN = "abcdefghijklmnopqrstuvwxyz";
	char *NUMBER = "0123456789";
	char *SYMBOL = "!@#$%^&*()_+=-.,/`\\[]{}|";
	char *source = malloc(strlen(LETTERS_UP) + strlen(LETTERS_DOWN) + strlen(NUMBER) + strlen(SYMBOL) + 2);
	int iargs=0;
	int option_index;

	const char *short_options = "hvl:c:P:udnse";
	const struct option long_options[] = {
		{ArgKeys[0].name, optional_argument, NULL, ArgKeys[0].sname},
		{ArgKeys[1].name, optional_argument, NULL, ArgKeys[1].sname},
		{ArgKeys[2].name, required_argument, NULL, ArgKeys[2].sname},
		{ArgKeys[3].name, required_argument, NULL, ArgKeys[3].sname},
		{ArgKeys[4].name, required_argument, NULL, ArgKeys[4].sname},
		{ArgKeys[5].name, optional_argument, NULL, ArgKeys[5].sname},
		{ArgKeys[6].name, optional_argument, NULL, ArgKeys[6].sname},
		{ArgKeys[7].name, optional_argument, NULL, ArgKeys[7].sname},
		{ArgKeys[8].name, optional_argument, NULL, ArgKeys[8].sname},
		{ArgKeys[9].name, optional_argument, NULL, ArgKeys[9].sname},
		{NULL, 0, NULL, 0}
	};

	strcat(source, "");

	//opterr = 0;
	while ( (iargs = getopt_long(argc, argv, short_options, long_options, &option_index)) != -1)
	{
		switch (iargs)
		{
			case 'h':
				Print.help();
				break;
			case 'v':
				Print.version();
				break;
			case 'l':
				if(isNumber(optarg) == 1)
				{
					sscanf(optarg, "%d", &length);
				} else {
					Print.error(_("Option %s must be a number!"), ArgKeys[2].manstr);
				}
				break;
			case 'c':
				if(isNumber(optarg) == 1)
				{
					sscanf(optarg, "%d", &count);
				} else {
					Print.error(_("Option %s must be a number!"), ArgKeys[3].manstr);
				}
				break;
			case 'P':
				usePattern = 1;
				*source = 0;
				strcat(source, optarg);
				break;
			case 'u':
				if (usePattern != 1)
					strcat(source, LETTERS_UP);
				break;
			case 'd':
				if (usePattern != 1)
					strcat(source, LETTERS_DOWN);
				break;
			case 'n':
				if (usePattern != 1)
					strcat(source, NUMBER);
				break;
			case 's':
				if (usePattern != 1)
					strcat(source, SYMBOL);
				break;
			case 'e':
				strcat(source, " ");
				break;
			case '?':
				exit(EXIT_FAILURE);
				break;
			default:
				break;
		};
	};

	/*
	if (optind < argc)
	{
		Print.echo("Not option ARGV elements (%d): ", (argc-1));
		while (optind < argc)
		{
			Print.echo("%s ", argv[optind++]);
		}
	}
	*/

	if (strlen(source) > 0)
	{
		while(count >= 1) {
			password = PassGen.getPassword(source, length);
			printf("%s\n", password);
			count--;
		}
	} else {
		Print.echo(_("One of the arguments %s, %s, %s, %s, %s is mandatory"), ArgKeys[4].manstr, ArgKeys[5].manstr, ArgKeys[6].manstr, ArgKeys[7].manstr, ArgKeys[8].manstr);
		exit(EXIT_FAILURE);
	}

	free(source);
	*source = 0;

	exit(EXIT_SUCCESS);
}
