#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * _print_char - print a character
 *
 * @args: list of arguments
 *
 * Return: Always 0 (Success)
 */

int _print_char(va_list args)
{
	char c = (char) va_arg(args, int);

	_putchar(c);
	return (0);
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
	int cp = 0;

	while (*s)
	{
		_putchar(*s++);
		cp++;
	}
	return (cp);
}
