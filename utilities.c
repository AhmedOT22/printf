#include "main.h"

/**
 * is_printable - check if a character is printable
 *
 * @c: char to check
 *
 * Return: 1 if success, 0 if fail
 */

int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - append ascii in hexadecimal to the buffer
 *
 * @buffer: an array of char
 * @i: index
 * @ascii: asci code
 *
 * Return: Always 3 (Success)
 */

int append_hexa_code(char ascii, char buffer[], int i)
{
	char map[] = "0123456789ABCDEF";

	if (ascii < 0)
		ascii *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map[ascii / 16];
	buffer[i] = map[ascii % 16];

	return (3);
}

/**
 * is_digit - check if a character is a digit
 *
 * @c: character to check
 *
 * Return: 1 if success, 0 if fail
 */

int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - cast a number to a specified size
 *
 * @num: number
 * @size: the size to convert to
 *
 * Return: the casted value of the number
 */

long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsigned - cast an unsigned number to a specified size
 * @num: number
 * @size: the size to convert to
 *
 * Return: the casted value of the number
 */

long int convert_size_unsigned(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
