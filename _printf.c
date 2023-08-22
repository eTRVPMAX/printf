#include "main.h"

/**
 * _printf - Prints formatted output to the standard output stream.
 * @format: A pointer to a constant format string.
 *
 * Return: The number of characters printed (excluding the null byte used to
 * end output to strings), or -1 if an error occurs.
 */
int _printf(const char *format, ...)
{
    int (*pfunc)(va_list, flags_t *);
    const char *p;
    va_list arguments;
    flags_t flags = {0, 0, 0};
    int count = 0;

    va_start(arguments, format);

    if (format == NULL || (format[0] == '%' && format[1] == '\0'))
    {
        va_end(arguments);
        return -1;
    }

    for (p = format; *p != '\0'; p++)
    {
        if (*p != '%')
        {
            count += _putchar(*p);
            continue;
        }

        p++;

        if (*p == '%')
        {
            count += _putchar('%');
            continue;
        }

        while (get_flag(*p, &flags))
            p++;

        pfunc = get_print(*p);

        if (pfunc)
            count += pfunc(arguments, &flags);
        else
            count += _printf("%%%c", *p);
    }

    _putchar(-1);

    va_end(arguments);

    return count;
}

