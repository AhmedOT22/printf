#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - structure for a specifier printing function
 *
 * @fmt: type of the specifier
 * @fn: the appropriate function for the specifier
 */

struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);

};

/**
 * typedef struct fmt fmt_t - structure
 *
 * @fmt: the format
 * @fm_t: the function
 */

typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int printing_handler(const char *fmt, int *index, va_list args, char buffer[],
		int flags, int width, int precision, int size);
int print_char(va_list args, char buffer[], int flags, int width,
		int precision, int size);
int print_string(va_list args, char buffer[], int flags, int width,
		int precision, int size);
int print_percent(va_list args, char buffer[], int flags, int width,
		int precision, int size);
int print_int(va_list args, char buffer[], int flags, int width, int precision,
		int size);
int print_binary(va_list args, char buffer[], int flags, int width,
		int precision, int size);
int print_pointer(va_list args, char buffer[], int flags, int width,
		int precision, int size);
int print_non_printable(va_list args, char buffer[], int flags, int width,
		int precision, int size);
int print_rot13string(va_list args, char buffer[], int flags, int width,
		int precision, int size);
int print_unsigned(va_list args, char buffer[], int flags, int width,
		int precision, int size);
int print_octal(va_list args, char buffer[], int flags, int width,
		int precision, int size);
int print_hexadecimal(va_list args, char buffer[], int flags, int width,
		int precision, int size);
int print_hexa_upper(va_list args, char buffer[], int flags, int width,
		int precision, int size);
int print_hexa(va_list args, char map[], char buffer[], int flags,
		char flag_ch, int width, int precision, int size);
int print_reverse(va_list args, char buffer[], int flags, int width,
		int precision, int size);
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list args);
int get_precision(const char *format, int *i, va_list args);
int get_size(const char *format, int *i);
int handle_write_char(char c, char buffer[], int flags, int width,
		int precision, int size);
int write_number(int is_positive, int index, char buffer[], int flags,
		int width, int precision, int size);
int write_num(int index, char buffer[], int flags, int width, int precision,
		int length, char padd, char extra_c);
int write_pointer(char buffer[], int index, int length, int width, int flags,
		char padd, char extra_c, int padd_start);
int write_unsigned(int is_negative, int index, char buffer[], int flags,
		int width, int precision, int size);
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_us(unsigned long int num, int size);

#endif
