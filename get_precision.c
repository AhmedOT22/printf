#include "main.h"

/**
 * get_precision - handle the printing precision
 *
 * @format: formatted string
 * @i: index
 * @args: list of arguments
 *
 * Return: the precision
 */

int get_precision(const char *format, int *i, va_list args)
{
	int current = *i + 1;
	int precision = -1;

	if(format[current] != '.')
		return (precision);

	precision = 0;

	for (current += 1; format[current] != '\0'; current++)
	{
		if (is_digit(format[current]))
		{
			precision *= 10;
			precision += format[current] - '0';
		}
		else if (format[current] == '*')
		{
			current++;
			precision = va_arg(args, int);
			break;
		}
		else
			break;
	}
	*i = current - 1;
	return (precision);
}
