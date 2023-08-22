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

	if (f->space == 1 && f->plus == 0 && n >= 0)
		final += _putchar(' ');
	if (f->plus == 1 && n >= 0)
		final += _putchar('+');
	if (n <= 0)
		final++;
	print_number(n);
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
	unsigned int n1 = n;
	int final = 0;

	if (n < 0)
	{
		final += _putchar('-');
		n1 = -n;
	}
	else
		n1 = n;

	if (n1 / 10)
		final += print_number(n1 / 10);
	final += _putchar((n1 % 10) + '0');

	return (final);
}

