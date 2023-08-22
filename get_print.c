#include "main.h"

/**
 * get_print - Selects the right printing function depending on the conversion specifier passed to _printf.
 * @s: The character that holds the conversion specifier.
 * return: A pointer to the matching printing function.
 */
int (*get_print(char s))(va_list, flags_t *)
{
    handler funcs_array[] = {
        {'i', print_int},
        {'s', print_string},
        {'c', print_char},
        {'d', print_int},
        {'u', print_unsigned},
        {'x', print_hex},
        {'X', print_hex_big},
        {'b', print_binary},
        {'o', print_octal},
        {'R', print_rot13},
        {'r', print_reverse},
        {'S', print_exS},
        {'p', print_address},
        {'%', print_percent}
    };
    int flags = sizeof(funcs_array) / sizeof(funcs_array[0]);

    register int i;

    for (i = 0; i < flags; i++) {
        if (funcs_array[i].c == s) {
            return funcs_array[i].f;
        }
    }

    return (NULL);
}

