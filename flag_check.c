#include "main.h"

/**
 * get_flag - turns on flags if _printf finds
 * a flag modifier in the format string
 * @s: character that holds the flag specifier
 * @f: pointer to the struct flags in which we turn the flags on
 * Return: 1 if a flag has been turned on, 0 otherwise
 */
int get_flag(char s, flags_t *f)
{
	int flag_set = 0;

	if (s == '+')
	{
		f->plus = 1;
		flag_set = 1;
	} else if (s == ' ')
	{
		f->space = 1;
		flag_set = 1;
	} else if (s == '#')
	{
		f->hash = 1;
		flag_set = 1;
	}

	return (flag_set);
}

