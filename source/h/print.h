#pragma once
/* print.h */

#ifndef __PRINT__
#define __PRINT__

/* Source: source/print.c */
struct print {
	/**
	 * @namespace Print
	 * @name help
	 * Функция выводит справочную
	 * информацию программы.
	 * @param length {&int} Длина пароля по-умолчанию
	 */
	void (*help)(int*);
	/**
	 * @namespace Print
	 * @name version
	 * Функция выводит версию релиза
	 */
	void (*version)();
	/**
	 * @namespace Print
	 * @name echo
	 * Функция выводит список переданных
	 * аргументов в виде форматированной
	 * строки в STDOUT.
	 * @param msg {char*} Строка в формате sprintf
	 * @param ... {} Аргументы для форматирования строки msg
	 */
	void (*echo)(char *const, ...);
};
extern const struct print Print;

#endif /* __PRINT__ */
