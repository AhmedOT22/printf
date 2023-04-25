#include "main.h"

/**
 * get_size - handle the size of the argument
 *
 * @format: formatted string
 * @i: index
 *
 * Return: the size
 */

int get_size(const char *format, int *i)
{
	int current = *i + 1;
	int size = 0;

	if (format[current] == '1')
		size = S_LONG;
	else if (format[current] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = current - 1;
	else
		*i = current;

	return (size);
}
