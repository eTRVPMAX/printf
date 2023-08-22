#include "main.h"

/**
 * print_int - prints an integer
 * @l: va_list of arguments from _printf
 * @f: pointer to the struct flags determining
 * if a flag is passed to _printf
 * Return: number of characters printed
 */
int print_int(va_list l, flags_t *f)
{
	int n = va_arg(l, int);
	int final = 0;
	int has_space = f->space == 1 && f->plus == 0 && n >= 0;
	int has_plus = f->plus == 1 && n >= 0;

	if (has_space)
		final += _putchar(' ');
	if (has_plus)
		final += _putchar('+');

	if (n < 0)
	{
		final += _putchar('-');
		n = -n;
	}

	final += print_number(n);

	return (final);
}

/**
 * print_unsigned - prints an unsigned integer
 * @l: va_list of arguments from _printf
 * @f: pointer to the struct flags determining
 * if a flag is passed to _printf
 * Return: number of characters printed
 */
int print_unsigned(va_list l, flags_t *f)
{
	unsigned int u = va_arg(l, unsigned int);
	char *str = convert(u, 10, 0);

	(void)f;
	return (_puts(str));
}

/**
 * print_number - helper function that prints an integer
 * @n: integer to be printed
 * Return: number of digits printed
 */
int print_number(int n)
{
	unsigned int n1 = (n < 0) ? -n : n;
	int final = 0;

	do {
		final += _putchar((n1 % 10) + '0');
		n1 /= 10;
	} while (n1 > 0);

	return (final);
}

