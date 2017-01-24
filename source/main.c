/* main.c */

#include "h/main.h"
#include "h/passgen.h"
#include "h/print.h"


int main (int argc, char * const argv[], char * const argp[])
{
	srand((unsigned) time(NULL) * getpid());
	setlocale(LC_ALL, "");
	bindtextdomain(PACKAGE_NAME, PACKAGE_LOCALE_DIR);
	textdomain(PACKAGE_NAME);

	int length = 25;
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
		{"help", optional_argument, NULL, 'h'},
		{"version", optional_argument, NULL, 'v'},
		{"length", required_argument, NULL, 'l'},
		{"count", required_argument, NULL, 'c'},
		{"pattern", required_argument, NULL, 'P'},
		{"letter-up", optional_argument, NULL, 'u'},
		{"letter-down", optional_argument, NULL, 'd'},
		{"number", optional_argument, NULL, 'n'},
		{"symbol", optional_argument, NULL, 's'},
		{"enable-space", optional_argument, NULL, 'e'},
		{NULL, 0, NULL, 0}
	};

	strcat(source, "");

	//opterr = 0;
	while ( (iargs = getopt_long(argc, argv, short_options, long_options, &option_index)) != -1)
	{
		switch (iargs)
		{
			case 'h':
				Print.help(&length);
				break;
			case 'v':
				Print.version();
				break;
			case 'l':
				sscanf(optarg, "%d", &length);
				break;
			case 'c':
				sscanf(optarg, "%d", &count);
				break;
			case 'P':
				usePattern = 1;
				*source = 0;
				strcat(source, optarg);
				break;
			case 'u':
				if (usePattern == 0)
					strcat(source, LETTERS_UP);
				break;
			case 'd':
				if (usePattern == 0)
					strcat(source, LETTERS_DOWN);
				break;
			case 'n':
				if (usePattern == 0)
					strcat(source, NUMBER);
				break;
			case 's':
				if (usePattern == 0)
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
		Print.echo(_("One of the arguments %s is mandatory"), "-u[--letter-up], -d[--letter-down], -n[--number], -s[--symbol], -P[--pattern]");
		exit(EXIT_FAILURE);
	}

	free(source);
	*source = 0;

	exit(EXIT_SUCCESS);
}
