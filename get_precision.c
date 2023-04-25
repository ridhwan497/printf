#include "main.h"
/**
 * _isdigit - checks if a character is a digit
 * @c: character to check
 * Return: 1 if c is a digit, 0 otherwise
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
/**
* get_precision - gets the precision for a format string
* @ptr: pointer to the format string
* @args: arguments passed to _printf
* @flags: struct containing formatting flags
* Return: ptr created.
*/

char *get_precision(char *ptr, flags_t *flags, va_list args)
{
	int precision = 0;

	ptr++;

	if (*ptr == '*')
	{
		precision = va_arg(args, int);
		if (precision >= 0)
			flags->precision = precision;
		ptr++;
	}
	else
	{
		while (_isdigit(*ptr))
		{
			precision = precision * 10 + (*ptr - '0');
			ptr++;
		}
		flags->precision = precision;
	}
	return (ptr);
}
