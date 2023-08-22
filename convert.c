#include "main.h"

/**
 * convert - Converts a number to string representation in the specified base.
 * @num: The number to convert.
 * @base: The base to use for conversion.
 * @uppercase: Whether to use uppercase letters for hexadecimal representation.
 * Return: The string representation of the number.
*/
char *convert(unsigned int num, int base, int uppercase)
{
	static char buffer[100];
	char *ptr = &buffer[99];
	const char *digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";

	*ptr = '\0';

	do {
		*--ptr = digits[num % base];
		num /= base;
	} while (num != 0);

	return (ptr);
}

