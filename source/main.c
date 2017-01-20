/* main.c */

#include "h/passgen.h"

void print_help(int length, char *source)
{
	printf("Консольный генератор паролей\n");
	printf("\n");
	printf("Параметры по-умолчанию:\n");
	printf("\tИспользуемые символы: %s\n", source);
	printf("\tДлина пароля:         %d\n", length);
	printf("\n");
	printf("Обязательные ключи:\n");
	printf("\t-l, --length    Длина пароля. Если не указан, то\n");
	printf("\t                он будет установлен в 25. Если указать 0,\n");
	printf("\t                то программа запросит ввод с клавиатуры.\n");
	printf("\n");
	printf("Остальные ключи:\n");
	printf("\t-h, --help      Справочная информация\n");
	printf("\t-d, --digest    Добавляет цифры к паролю\n");
	printf("\t-s, --symbol    Добавляет знаки пунктуации к паролю\n");
	printf("\n");
	printf("Примеры использования:\n");
	printf("\t$ passgen -l25 # Используем только английские буквы в верхнем и нижнем регистре\n");
	printf("\t$ passgen -l25 -d # Добавляем цифры\n");
	printf("\t$ passgen -l25 -s # Добавляем знаки пунктуации, но не используем цифры\n");
	printf("\t$ passgen -l25 -ds # Добавляем знаки пунктуации и цифры\n");
	exit(0);
}

void print_usage()
{
	printf("Usage: \npassgen -h[--help]\n");
	exit(0);
}

int main (int argc, char * const argv[])
{
	int length = 25;
	char *password;
	char *ALPHABETS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char *DIGEST = "0123456789";
	char *SYMBOLS = "!@#$%^&*()_+=-.,/`\\[]{}|";
	char *source = malloc(strlen(ALPHABETS) + strlen(DIGEST) + strlen(SYMBOLS) + 1);;
	int iargs=0;
	int option_index;
	const char *short_options = "hl:ds";

	const struct option long_options[] = {
		{"help", optional_argument, NULL, 'h'},
		{"length", required_argument, NULL, 'l'},
		{"digest", optional_argument, NULL, 'd'},
		{"symbol", optional_argument, NULL, 's'},
		{NULL, 0, NULL, 0}
	};

	strcat(source, ALPHABETS);

	if(argc <= 1) {
		print_usage();
	}

	//opterr = 0;
	while ( (iargs = getopt_long(argc, argv, short_options, long_options, &option_index)) != -1) {
		switch (iargs){
			case 'h': {
				print_help(length, source);
				break;
			}
			case 'l': {
				sscanf(optarg, "%d", &length);
				break;
			}
			case 'd': {
				strcat(source, DIGEST);
				break;
			}
			case 's': {
				strcat(source, SYMBOLS);
				break;
			}
			case '?': default: {
				printf("Unknown ERROR\n");
				break;
			}
		};
	};

	password = genpass(source, length);

	printf("%s\n", password);

	return 0;
}
