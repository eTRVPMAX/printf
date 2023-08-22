#include "main.h"

/**
 * print_exS - prints non-printable characters
 * @l: va_list arguments from _printf
 * @f: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: number of characters printed
 */
int print_exS(va_list l, flags_t *f)
{
    int count = 0;
    char *s = va_arg(l, char *);
    char *res;
    int i;

    (void)f;
    if (!s)
        return _puts("(null)");

    for (i = 0; s[i]; i++)
    {
        if (s[i] > 0 && (s[i] < 32 || s[i] >= 127))
        {
            _puts("\\x");
            count += 2;
            res = convert(s[i], 16, 1);
            if (!res[1])
                count += _putchar('0');
            count += _puts(res);
        }
        else
            count += _putchar(s[i]);
    }

    return (count);
}

/**
 * print_reverse - prints a string in reverse
 * @l: va_list arguments from _printf
 * @f: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: number of characters printed
 */
int print_reverse(va_list l, flags_t *f)
{
    char *s = va_arg(l, char *);
    int i = 0;
    int j;

    (void)f;
    if (s == NULL)
        s = "(null)";

    while (s[i])
        i++;

    for (j = i - 1; j >= 0; j--)
        _putchar(s[j]);

    return (i);
}

/**
 * print_rot13 - prints a string using ROT13 encryption
 * @l: va_list arguments from _printf
 * @f: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: number of characters printed
 */
int print_rot13(va_list l, flags_t *f)
{
    char *s = va_arg(l, char *);

    unsigned char rot13_lookup[256];
    int i;

    char rot13[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char ROT13[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";

    for (i = 0; i < 256; i++)
        rot13_lookup[i] = i;

    for (i = 0; rot13[i]; i++)
    {
        rot13_lookup[(unsigned char)rot13[i]] = ROT13[i];
        rot13_lookup[(unsigned char)ROT13[i]] = rot13[i];
    }

    (void)f;
    for (i = 0; s[i]; i++)
    {
        _putchar(rot13_lookup[(unsigned char)s[i]]);
    }

    return (_strlen(s));
}

/**
 * print_percent - prints a percent symbol
 * @l: va_list arguments from _printf
 * @f: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: number of characters printed
 */
int print_percent(va_list l, flags_t *f)
{
    (void)l;
    (void)f;
    return (_putchar('%'));
}

