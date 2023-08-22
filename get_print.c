#include "main.h"

/**
 * get_print - selects the right printing function
 * depending on the conversion specifier passed to _printf
 * @s: character that holds the conversion specifier
 * Description: the function loops through the structs array
 * func_arr[] to find a match between the specifier passed to _printf
 * and the first element of the struct, and then the approriate
 * printing function
 * Return: a pointer to the matching printing function
 */
int (*get_print(char s))(va_list, flags_t *)
{
	handler funcs_array[] = {
		{'s', print_string},
		{'c', print_char},
		{'u', print_unsigned},
		{'R', print_rot13},
		{'r', print_reverse},
		{'S', print_exS},
		{'%', print_percent}
	};
	int flags = sizeof(funcs_array) / sizeof(funcs_array[0]);

	register int i;

	for (i = 0; i < flags; i++)
	{
		if (funcs_array[i].c == s)
		{
			return (funcs_array[i].f);
		}
	}

	return (NULL);
}

