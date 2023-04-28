#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "main.h"

/**
 * print_buffer - prints the buffer's contents
 *
 * @buffer: array of chars
 * @buff_index: the index in the buffer
 */

void print_buffer(char buffer[], int *buff_index)
{
	if (*buff_index > 0)
		write(1, &buffer[0], *buff_index);
	*buff_index = 0;
}

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
	int i, counter = 0, is_printed = 0;
	int flags, width, precision, size, buff_index = 0;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_index] = format[i];
			if (buff_index == BUFF_SIZE)
				print_buffer(buffer, &buff_index);
			counter++;
		}

		else
			print_buffer(buffer, &buff_index);
			flags = get_flags(format, &i);
			width = get_width(format, &i, args);
			precision = get_precision(format, &i, args);
			size = get_size(format, &i, args);
			++i;
			is_printed = printing_handler(format, &i, args, buffer, flags, width,
					precision, size);
			if (is_printed == -1)
				return (-1);
			counter += is_printed;
		}
	}
	print_buffer(buffer, &buff_index);

	va_end(args);
	return (counter);
}
