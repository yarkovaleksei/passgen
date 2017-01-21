/* passgen.c */

#include "h/passgen.h"


char getChar(char *symbols);

/**
 * @name genpass
 * Функция генерирует строку из случайных
 * символов и возвращает её.
 * @param symbols {char*} Строка, символы которой будут использоваться в генераторе
 * @param length {int} Длина пароля
 * @return Строка из случайных символов длиной length
 */
char *genpass(char *symbols, int length)
{
	srandom(time(NULL));
	int counter = 0;
	char *result = malloc(length + 1);

	if(length < 1) {
		printf(_("Type in a password length\n"));
		scanf("%d", &length);
	}

	while(counter < length)
	{
		result[counter] = getChar(symbols);
		counter++;
	}

	strcat(result, "\0");
	return result;
}


/**
 * @name getChar
 * Возвращает один случайный символ из переданной в аргументе строки
 * @param symbols {char*} Строка, из которой будет взят один случайный символ
 * @return Случайный символ из строки symbols
 */
char getChar(char *symbols)
{
	return symbols[random () % strlen(symbols)];
}

