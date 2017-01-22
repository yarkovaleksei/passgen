/* passgen.c */

#include "h/passgen.h"


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


/**
 * @name getPassword
 * Функция генерирует строку из случайных
 * символов и возвращает её.
 * @param symbols {char*} Строка, символы которой будут использоваться в генераторе
 * @param length {int} Длина пароля
 * @return Строка из случайных символов длиной length
 */
char *getPassword(char *symbols, int length)
{
	int counter = 0;
	char *result = malloc(length + 1);

	if(length < 1) {
		printf("%s\n", _("Type in a password length"));
		scanf("%d", &length);
	}

	while(counter < length) {
		result[counter] = getChar(symbols);
		counter++;
	}

	strcat(result, "\0");
	return result;
}


const struct passgen PassGen = {
	.getPassword = getPassword,
	.getChar = getChar
};
