/* main.c */

#include "h/passgen.h"


void print_help(int *length, char **source);
void print_version();


int main (int argc, char * const argv[], char * const argp[])
{
	srandom(time(NULL));
	setlocale(LC_ALL, "");
	bindtextdomain(PACKAGE, LOCALEDIR);
	textdomain(PACKAGE);

	int length = 25;
	int count = 1;
	char *password;
	char *ALPHABETS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char *DIGEST = "0123456789";
	char *SYMBOLS = "!@#$%^&*()_+=-.,/`\\[]{}|";
	char *source = malloc(sizeof(ALPHABETS) + sizeof(DIGEST) + sizeof(SYMBOLS) + 1);;
	int iargs=0;
	int option_index;
	const char *short_options = "hvl:c:ds";
	const struct option long_options[] = {
		{"help", optional_argument, NULL, 'h'},
		{"version", optional_argument, NULL, 'v'},
		{"length", required_argument, NULL, 'l'},
		{"count", required_argument, NULL, 'c'},
		{"digest", optional_argument, NULL, 'd'},
		{"symbol", optional_argument, NULL, 's'},
		{NULL, 0, NULL, 0}
	};

	strcat(source, ALPHABETS);

	//opterr = 0;
	while ( (iargs = getopt_long(argc, argv, short_options, long_options, &option_index)) != -1) {
		switch (iargs){
			case 'h':
				print_help(&length, &source);
				break;
			case 'v':
				print_version();
				break;
			case 'l':
				sscanf(optarg, "%d", &length);
				break;
			case 'c':
				sscanf(optarg, "%d", &count);
				break;
			case 'd':
				strcat(source, DIGEST);
				break;
			case 's':
				strcat(source, SYMBOLS);
				break;
			case '?':
				exit(EXIT_FAILURE);
				break;
			default:
				break;
		};
	};

	/*if (optind < argc) {
		printf("non-option ARGV-elements (%d): ", (argc-1));
		while (optind < argc) {
			printf("%s ", argv[optind++]);
		}
		printf("\n");
	}*/

	while(count >= 1) {
		password = PassGen.getPassword(source, length);
		printf("%s\n", password);
		count--;
	}

	free(source);
	*source = 0;

	exit(EXIT_SUCCESS);
}


void print_help(int *length, char **source)
{
	printf(_("Console password generator\n"));
	printf("\n");
	printf(_("Default values:\n"));
	printf(_("\tUsage symbols:     %s\n"), *source);
	printf(_("\tPassword length:   %d\n"), *length);
	printf("\n");
	printf(_("Usage keys:\n"));
	printf(_("\t-h, --help      Help information\n"));
	printf(_("\t-v, --version   Package version\n"));
	printf(_("\t-l, --length    Password length. If not specified,\n"));
	printf(_("\t                it will be set to 25. If set to 0,\n"));
	printf(_("\t                the program will ask for input from the keyboard.\n"));
	printf(_("\t-c, --count     The amount for one time passwords.\n"));
	printf(_("\t                It is useful when you need to create\n"));
	printf(_("\t                a file with a unique string.\n"));
	printf(_("\t-d, --digest    Adds the numbers in the password\n"));
	printf(_("\t-s, --symbol    Adds punctuation to the password\n"));
	printf("\n");
	printf(_("Example:\n"));
	printf(_("\t$ %s -l25      # Only English letters in upper and lower case\n"), PACKAGE);
	printf(_("\t$ %s -l25 -d   # Adds the numbers\n"), PACKAGE);
	printf(_("\t$ %s -l25 -s   # Adding punctuation marks, but do not use numbers\n"), PACKAGE);
	printf(_("\t$ %s -l25 -ds  # Adding punctuation and numbers\n"), PACKAGE);
	printf(_("\t$ %s -l25 -c5  # List of the 5 passwords, one per line\n"), PACKAGE);
	exit(EXIT_SUCCESS);
}

void print_version()
{
	printf("%s\n", VERSION);
	exit(EXIT_SUCCESS);
}
