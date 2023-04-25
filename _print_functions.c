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

/**
 * print_int - Print int
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
	buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) n);
		is_negative = 1;
	}

	while (num > 0)
	{
	buffer[i--] = (num % 10) + '0';
	num /= 10;
	}

	i++;

	return (write_number(is_negative, i, buffer, flags, width, precision, size));
}

/**
 * print_binary - Prints an unsigned number
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of char printed.
 */
int print_binary(va_list types, char buffer[],
    int flags, int width, int precision, int size)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(types, unsigned int);
	m = 2147483648; / (2 ^ 31) / a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
