/* print.h */

#ifndef __PRINT__
#define __PRINT__

/* Source: source/print.c */
struct print {
	/**
	 * @namespace Print
	 * @name help
	 * Функция выводит справочную информацию программы
	 */
	void (*help)();
	/**
	 * @namespace Print
	 * @name version
	 * Функция выводит версию релиза
	 */
	void (*version)();
	/**
	 * @namespace Print
	 * @name echo
	 * Функция выводит список переданных аргументов
	 * в виде форматированной строки в STDOUT.
	 * @param msg {char*} Строка в формате sprintf
	 * @param ... {} Аргументы для форматирования строки msg
	 */
	void (*echo)(char *const, ...);
	/**
	 * @namespace Print
	 * @name error
	 * Функция выводит список переданных аргументов
	 * в виде форматированной строки в STDERR.
	 * @param msg {char*} Строка в формате sprintf
	 * @param ... {} Аргументы для форматирования строки msg
	 */
	void (*error)(char *const, ...);

	char* (*fmt_help)(int);

	char* (*fmt_man)(int);
};
extern const struct print Print;

#endif /* __PRINT__ */
