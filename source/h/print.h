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
	 * @param {char*} msg Строка в формате sprintf
	 * @param {va_list} ... Аргументы для форматирования строки msg
	 */
	void (*echo)(char *const, ...);
	/**
	 * @namespace Print
	 * @name error
	 * Функция выводит список переданных аргументов
	 * в виде форматированной строки в STDERR и завершает работу
	 * программы с ошибкой.
	 * @param {char*} msg Строка в формате sprintf
	 * @param {va_list} ... Аргументы для форматирования строки msg
	 */
	void (*error)(char *const, ...);
};
extern const struct print Print;

#endif /* __PRINT__ */
