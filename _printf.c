#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - a printf like function
 *
 * @format: the format specifier
 *
 * Return: printed element count
 */

int _printf(const char *format, ...)
{
	va_list args;

	char *(f)(va_list);
	int i, counter;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	counter = 0;
	i = 0;

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			/*write(1, &format[i], 1);*/
			_putchar(format[i]);
			counter++;
		else
			i++;
			f = printing_handler(&format[i]);
			if (f == NULL)
				return (-1);
			counter += f(args);
		}
	}


	va_end(args);
	return (counter);
}
