/* passgen.h */

#ifndef __PASSGEN__
#define __PASSGEN__

/* Source: source/passgen.c */
struct passgen {
	/**
	 * @namespace PassGen
	 * @name getPassword
	 * Функция генерирует строку из случайных
	 * символов и возвращает её.
	 * @param {char*} symbols Строка, символы которой будут использоваться в генераторе
	 * @param {int} length Длина пароля
	 * @return Строка из случайных символов длиной length
	 */
	char* (*getPassword)(char*, int);
	/**
	 * @namespace PassGen
	 * @name getChar
	 * Возвращает один случайный символ из переданной в аргументе строки
	 * @param {char*} symbols Строка, из которой будет взят один случайный символ
	 * @return Случайный символ из строки symbols
	 */
	char (*getChar)(char*);
};
extern const struct passgen PassGen;

#endif /* __PASSGEN__ */
