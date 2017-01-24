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
	 * @param symbols {char*} Строка, символы которой будут использоваться в генераторе
	 * @param length {int} Длина пароля
	 * @return Строка из случайных символов длиной length
	 */
	char* (*getPassword)(char*, int);
	/**
	 * @namespace PassGen
	 * @name getChar
	 * Возвращает один случайный символ из переданной в аргументе строки
	 * @param symbols {char*} Строка, из которой будет взят один случайный символ
	 * @return Случайный символ из строки symbols
	 */
	char (*getChar)(char*);
};
extern const struct passgen PassGen;

/* Source: <getopt.h> */
int getopt_long(int argc, char * const argv[], const char *optstring, const struct option *longopts, int *longindex);
extern char *optarg;
extern int optind, opterr, optopt;

#endif /* __PASSGEN__ */
