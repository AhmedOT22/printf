#include "main.h"

/**
 * printing_handler - handle the conversion specifier and the printing method
 *
 * @fmt: the list of conversion specifier
 * @index: the index in the list
 * @args: list of aruments
 * @buffer: buffer array to handle print
 * @flags: check for active flags
 * @width: width
 * @precision: precision
 * @size: size
 * Return: the count of printed characters
 */

int printing_handler(const char *fmt, int *index, va_list args, char buffer[],
			int flags, int width, int precision, int size)
{
	int i, counter = 0, length = 0;

	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string},
		{'%', print_percent}, {'i', print_int},
		{'d', print_binary}, {'u', print_unsigned},
		{'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer},
		{'S', print_non_printable}, {'r', print_reverse},
		{'r', print_reverse}, {'R', print_rot13string},
		{'\0', NULL}
	};

	for (i = 0; fmt_types[i].fmt != '\0'; i++)
	{
		if (fmt[*index] == fmt_types[i].fmt)
		{
			return (fmt_types[i].fn(args, buffer, flags, width, precision, size));
		}
	}
	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*index] == '\0')
			return (-1);
		length += write(1, "%%", 1);
		if (fmt[*index - 1] == ' ')
			length += write(1, " ", 1);
		else if (width)
		{
			--(*index);
			while (fmt[*index] != ' ' && fmt[*index] != '%')
				--(*index);
			if (fmt[*index] == ' ')
				--(*index);
			return (1);
		}
		length += write(1, &fmt[*index], 1);
		return (length);
	}
	return (counter);
}
