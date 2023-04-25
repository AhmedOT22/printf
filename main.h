#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

/**
 * struct specifier - structure for a specifier printing function
 *
 * @type: type of the specifier
 * @function: the appropriate function for the specifier
 */

typedef struct specifier
{
	char type;
	int (*function)(va_list);

} spec_list;

/**
 * printing_handler - handle the conversion specifier and the printing method
 *
 * @spec_list: the list of conversion specifier
 * @index: the index in the list
 * @list: list of aruments
 *
 * Return: the count of printed characters
 */

int printing_handler(const char *spec_list, int *index, va_list list)
{
	int i, counter = 0;
	spec_list specs[] = {
		{'c', _print_char}, {'s', _print_string}, {'%', _print_percent}, {'\0', NULL}
	};

	for (i = 0; specs[i].type != '\0'; i++)
	{
		if (spec_list[*index] == specs[i].type)
		{
			counter += specs[i].function(list);
			break;
		}
	}
	if (specs[i].type == '\0')
	{
		if (spec_list[*index] == '\0')
			return (-1);
		_putchar(spec_list[*index]);
		counter++;
	}
	return (counter);
}

int _putchar(char c);
int _printf(const char *format, ...);
int _print_char(va_list args);
int _print_string(va_list args);
int _print_percent(va_list args);

#endif
