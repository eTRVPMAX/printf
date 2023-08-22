#include "main.h"


/**
 * print_base - prints a number in the specified base
 * @l: va_list arguments from _printf
 * @f: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * @base: the base to convert the number to (2, 8, 10, 16)
 * @uppercase: flag indicating if the output should be in uppercase
 * Return: number of characters printed
 */
int print_base(va_list l, flags_t *f, int base, int uppercase)
{
    unsigned int num = va_arg(l, unsigned int);
    char *str = convert(num, base, uppercase);
    int count = 0;

    if (f->hash == 1 && str[0] != '0')
    {
        if (base == 2)
            count += _puts("0b");
        else if (base == 8)
            count += _putchar('0');
        else if (base == 16)
            count += _puts(uppercase ? "0X" : "0x");
    }

    count += _puts(str);

    return count;
}

/**
 * print_binary - prints a number in base 2
 * @l: va_list arguments from _printf
 * @f: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: number of characters printed
 */
int print_binary(va_list l, flags_t *f)
{
    return print_base(l, f, 2, 0);
}

/**
 * print_octal - prints a number in base 8
 * @l: va_list arguments from _printf
 * @f: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: number of characters printed
 */
int print_octal(va_list l, flags_t *f)
{
    return print_base(l, f, 8, 0);
}

/**
 * print_hex - prints a number in hexadecimal base, in lowercase
 * @l: va_list arguments from _printf
 * @f: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: number of characters printed
 */
int print_hex(va_list l, flags_t *f)
{
    return print_base(l, f, 16, 1);
}

/**
 * print_hex_big - prints a number in hexadecimal base, in uppercase
 * @l: va_list arguments from _printf
 * @f: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: number of characters printed
 */
int print_hex_big(va_list l, flags_t *f)
{
    return print_base(l, f, 16, 0);
}

