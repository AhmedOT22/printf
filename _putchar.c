#include <unistd.h>

/**
 * _putchar - writes a chracter to stdout
 *
 * @c: character to print
 *
 * Return: 1 if success, -1 otherwise
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
