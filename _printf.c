#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * _printf - a printf like function
 *
 * @format: format
 *
 * Return: printed element count
 */

int _printf(const char *format, ...)
{
	va_list args;
	char c;
	char *s;
	int counter;

	while (*format)
	{
		switch (*format)
		{
			case 'c':
				c = va_arg(args, int);
				putchar(c);
				counter++;
				break;
			case 's':
				s = va_arg(args, char*);
				for (; *s != '\0'; s++)
				{
					putchar(*s);
					counter++;
				}
				break;
			case '%':
				putchar('%');
				counter++;
				break;
			default:
				break;
		}
		format++;

	}
	va_end(args);
	return (counter);
}
