/* main.c */

#include "h/passgen.h"


void print_help(int *length, char **source);
void print_version();
void print_log(char * const msg, ...);

int main (int argc, char * const argv[], char * const argp[])
{
	srandom(time(NULL));
	setlocale(LC_ALL, "");
	bindtextdomain(PACKAGE, LOCALEDIR);
	textdomain(PACKAGE);

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
			case 'P':
				usePattern = 1;
				*source = 0;
				strcat(source, optarg);
				break;
			case 'u':
				if (usePattern == 0) {
					strcat(source, LETTERS_UP);
				}
				break;
			case 'd':
				if (usePattern == 0) {
					strcat(source, LETTERS_DOWN);
				}
				break;
			case 'n':
				if (usePattern == 0) {
					strcat(source, NUMBER);
				}
				break;
			case 's':
				if (usePattern == 0) {
					strcat(source, SYMBOL);
				}
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

	/*if (optind < argc) {
		printf("non-option ARGV-elements (%d): ", (argc-1));
		while (optind < argc) {
			printf("%s ", argv[optind++]);
		}
		printf("\n");
	}*/

	if (strlen(source) > 0) {
		while(count >= 1) {
			password = PassGen.getPassword(source, length);
			printf("%s\n", password);
			count--;
		}
	}
	else {
		print_log(_("One of the arguments %s is mandatory"), "-u[--letter-up], -d[--letter-down], -n[--number], -s[--symbol], -P[--pattern]");
		exit(EXIT_FAILURE);
	}

	free(source);
	*source = 0;

	exit(EXIT_SUCCESS);
}


void print_help(int *length, char **source)
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
	printf("\t$ %s -l0  -u                # %s\n", PACKAGE, _("Input length from the keyboard"));
	printf("\t$ %s -l25 -d                # %s\n", PACKAGE, _("Use the lowercase letters only"));
	printf("\t$ %s -l25 -s                # %s\n", PACKAGE, _("Use punctuation marks only"));
	printf("\t$ %s -l25 -dn               # %s\n", PACKAGE, _("Use lowercase letters and numbers only"));
	printf("\t$ %s -l25 -du               # %s\n", PACKAGE, _("Use lowercase and uppercase letters only"));
	printf("\t$ %s -l25 -P123abc          # %s\n", PACKAGE, _("Use symbols '123abc' only"));
	printf("\t$ %s -l25 -P123abc -e       # %s\n", PACKAGE, _("Use symbols '123abc' with space"));
	printf("\t$ %s -l25 -c5               # %s\n", PACKAGE, _("List of the 5 passwords, one per line"));
	exit(EXIT_SUCCESS);
}

void print_version()
{
	printf("%s\n", VERSION);
	exit(EXIT_SUCCESS);
}

void print_log(char * const msg, ...)
{
	va_list arguments;
	char *format = (char*)malloc((sizeof(PACKAGE) + sizeof(VERSION) + sizeof(msg)) * sizeof(arguments));
	sprintf(format, "[%s-%s]: %s\n", PACKAGE, VERSION, msg);
	va_start(arguments, msg);
	vprintf(format, arguments);
	va_end(arguments);
}
