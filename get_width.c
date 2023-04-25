#include "main.h"

/**
 * get_width - handle the field width
 *
 * @format: formatted string
 * @i: index
 * @args: list of arguments
 *
 * Return: the width
 */

int get_width(const char *format, int *i, va_list args)
{
	int current;
	int width = 0;

	for (current = *i + 1; format[current] != '\0'; current++)
	{
		if (is_digit(format[current]))
		{
			width *= 10;
			width += format[current] - '0';
		}
		else if (format[current] == '*')
		{
			current++;
			width = va_arg(args, int);
			break;
		}
		else
			break;
	}
	*i = current - 1;
	return (width);
}
