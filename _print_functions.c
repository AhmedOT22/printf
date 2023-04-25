#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * _print_char - print a character
 *
 * @args: list of arguments
 *
 * Return: the count of printed characters
 */

int _print_char(va_list args)
{
	char c = (char) va_arg(args, int);

	return (_putchar(c));
}

/**
 * _print_string - print a string
 *
 * @args: list of arguments
 *
 * Return: the count of printed characters
 */

int _print_string(va_list args)
{
	char *s = va_arg(args, char *);

	if (s == NULL)
	{
		s = "(null)";

	return (write(1, s));
}

/**
 * print_percent - print the % symbol
 *
 * @args: list of arguments
 *
 * Return: the count of printed characters
 */

int print_percent(va_list args)
{
	return (write(1, "%%", 1));
}
