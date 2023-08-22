#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>

#define BUFFER_SIZE 1024

/**
 * struct buff - Struct to hold the output buffer and its index.
 * @buffer: Buffer to store characters.
 * @index: Index to track the next available position in the buffer.
 */
typedef struct buff
{
	char buffer[BUFFER_SIZE];
	int index;
} OutputBuffer;


/**
 * struct flags - struct containing flags to "turn on"
 * when a flag specifier is passed to _printf()
 * @plus: flag for the '+' character
 * @space: flag for the ' ' character
 * @hash: flag for the '#' character
 */
typedef struct flags
{
	int plus;
	int space;
	int hash;
} flags_t;

/**
 * struct printHandler - struct to choose the right function depending
 * on the format specifier passed to _printf()
 * @c: format specifier
 * @f: pointer to the correct printing function
 */
typedef struct printHandler
{
	char c;
	int (*f)(va_list ap, flags_t *f);
} handler;


int print_int(va_list l, flags_t *f);
int print_number(int n);
int print_unsigned(va_list l, flags_t *f);
int count_digit(int i);
int print_hex(va_list l, flags_t *f);
int print_hex_big(va_list l, flags_t *f);
int print_binary(va_list l, flags_t *f);
int print_octal(va_list l, flags_t *f);
char *convert(unsigned int num, int base, int uppercase);
int _printf(const char *format, ...);
void print_buffer(char buffer[], int *buff_ind);
int (*get_print(char s))(va_list, flags_t *);
int print_string(va_list l, flags_t *f);
int print_char(va_list l, flags_t *f);
int _strlen(const char *s);
int _putchar(char c);
int _puts(char *str);
int print_rot13(va_list l, flags_t *f);
int print_reverse(va_list l, flags_t *f);
int print_exS(va_list l, flags_t *f);
int print_percent(va_list l, flags_t *f);
int get_flag(char s, flags_t *f);
#endif

