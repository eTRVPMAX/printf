#include "main.h"

/**
 * print_string - Prints a string
 * @l: va_list arguments from _printf
 * @f: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: number of characters printed
 */
int print_string(va_list l, flags_t *f)
{
	char *s = va_arg(l, char *);

	(void)f;

	if (s == NULL)
		s = "(null)";
	return (_puts(s));
}

/**
 * print_char - prints a character
 * @l: va_list arguments from _printf
 * @f: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: number of char printed
 */
int print_char(va_list l, flags_t *f)
{
	char s;
	(void)f;
	s = va_arg(l, int);
	_putchar(s);
	return (1);
}

/**
 * _strlen - Computes the length of a string
 * @s: The string to compute the length of
 * Return: The length of the string
 */
int _strlen(const char *s)
{
	int len = 0;

	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

