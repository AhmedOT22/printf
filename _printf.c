#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * print_format - choose the appropriate function for the specifier
 *
 * @format: the format specifier
 *
 * Return: pointer to the function to print
 */

static int (*print_format(const char * format))(va_list)
{
	int i;
	specifier_list spec[] = 
	{
		{"c", _print_char},
		{"s", _print_string},
		{NULL, NULL}
	};

	for (i = 0; spec[i].type != NULL; i++)
	{
		if(*(spec[i].type) == *format)
			break;
	}
	return (p[i].function);
}

/**
 *
 * _printf - a printf like function
 *
 * @format: the format specifier
 *
 * Return: printed element count
 */

int _printf(const char *format, ...)
{
	va_list args;
	char *f(va_llist);
	int i, counter;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	counter = 0;
	i = 0;

	while (*format)
	{
		for (; format[i] != '%'; i++)
		{
			_putchar(format[i]);
			counter++;
		}
		if (!format[i])
			return (counter);
		f = print_format(&format[i + 1]);
		if (f != NULL)
		{
			counter += f(args);
			i = i + 2;
			continue;
		}
		if (!format[i + 1])
			return (-1);
		_putchar(format[i];
		counter ++;
		if (format[i + 1] == '%')
			i = i + 2;
		else
			i++;
	}


	va_end(args);
	return (counter);
}
