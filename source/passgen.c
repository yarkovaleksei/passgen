/* passgen.c */

#include "h/main.h"
#include "h/print.h"
#include "h/passgen.h"
#include "h/valid.h"


char getChar(char *symbols)
{
	return symbols[rand () % strlen(symbols)];
}

char *getPassword(char *symbols, int length)
{
	int counter = 0;
	int isTyped = 0;
	char *result = malloc(length + 1);

	if (length < 1)
	{
		while (isTyped != 1)
		{
			int t;
			char ct[5] = {0};
			printf("%s:\n>>> ", _("Type in a password length. Use only 4 first symbols."));
			/**
			 * Если не присвоить вызов scanf переменной,
			 * то компилятор выдаст warning: -Wunused-result
			 */
			int _readchar = scanf("%4s", ct);

			/**
			 * Если не использовать переменную,
			 * то компилятор выдаст warning: -Wunused-variable
			 */
			if (_readchar < 1) {
				// Аварийный выход сработает если, например,
				// в режиме ввода нажать Ctrl+D
				exit(EXIT_FAILURE);
			}

			// Если введенная строка состоит из цифр
			if (isNumber(ct) == 1)
			{
				// Конвертируем в число
				t = atoi(ct);
				// Нельзя иметь длину пароля < 0 )))
				if (t < 1) {
					isTyped = 0;
				} else {
					length = t;
					isTyped = 1;
				}
			} else {
				isTyped = 0;
			}
		}
	}

	if (length > MAX_PASSWORD_LENGTH) {
		Print.error("%s: %d", _("Max password length"), MAX_PASSWORD_LENGTH);
	}

	while(counter < length)
	{
		result[counter] = getChar(symbols);
		counter++;
	}

	result[counter] = '\0'; // НАДО ИСПОЛЬЗОВАТЬ ОДИНАРНЫЕ КАВЫЧКИ
	return result;
}


const struct passgen PassGen = {
	.getPassword = getPassword,
	.getChar = getChar
};
