#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

/**
 * struct format_struct - structure for a specifier printing function
 *
 * @type: type of the specifier
 * @function: the appropriate function for the specifier
 */

typedef struct format_struct
{
	char *type;
	int (*function)(va_list);

}specifier_list;

int _putchar(char c);
int _printf(const char *format, ...);
int _print_char(va_list args);
int _print_string(va_list args);

#endif
