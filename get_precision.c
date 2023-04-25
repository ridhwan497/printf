#include "main.h"

/**
* get_precision - gets the precision for a str
* @ptr: pointer to the format string
* @args: arguments passed to _printf
* @flags: struct containing formatting flags
* Return: ptr created.
*/

char *get_precision(char *ptr, flags_t *flags, va_list args)
{
	int precision = 0;

	if (*ptr != '.')
		return (ptr);
	ptr++;
	if (*ptr == '*')
	{
		precision = va_arg(args, int);
		ptr++;
	}
	else
	{
		while (_isdigit(*ptr))
			precision = precision * 10 + (*ptr++ - '0');
	}
	flags->precision = precision;
	return (ptr);
}
