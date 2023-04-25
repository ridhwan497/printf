#include "main.h"

/**
 * handle_format_specifier - handles format specifiers
 * @ptr: pointer to the format string
 * @args: arguments passed to _printf
 * @flags: struct containing formatting flags
 * Return: number of characters printed
 */

int (*handle_format_specifier(char *ptr))(va_list args, flags_t *flags)
{
	int index = 0;
	print_t print[] = 
	{
		{"c", print_ch},
		{"s", print_string},
		{"d", print_integer},
		{"i", print_integer},
		{"b", print_binary},
		{"u", unsigned_num},
		{"o", print_octal_number},
		{"x", print_hex_lowercase},
		{"X", print_hex_uppercase},
		{"p", print_pointer},
		{"r", print_reverse},
		{"R", print_rot13},
		{"S", print_custom},
		{"%", print_percent},
	};

	while (print[index].c)
	{
		if (*ptr == print[index].c[0])
			return (print[index].f);
		index++;
	}
	return (NULL); /* if no match is found */
}

/**
 * format_function - handles format specifiers 
 * @ptr: pointer to the format string
 * @arg: arguments passed 
 * @flags: struct containing formatting flags
 * Return: number of characters printed
 */

int format_function(char *ptr, va_list arg, flags_t *flags)
{
	int (*f)(va_list, flags_t *);

	f = handle_format_specifier(ptr);
	if (f)
		return (f(arg, flags));
	else
		return (0);
}
/**
 * get_modifier - gets the modifier for a format string
 * @ptr: pointer to the format string
 * @flags: struct containing formatting flags
 * Return: ptr created.
 */
 
char *get_modifier(char *ptr, flags_t *flags)
{
	switch (*ptr)
	{
	case 'h':
		if (*(ptr + 1) == 'h')
		{
			flags->modifier = HH;
			ptr++;
		}
		else
			flags->modifier = H;
		break;
	case 'l':
		if (*(ptr + 1) == 'l')
		{
			flags->modifier = LL;
			ptr++;
		}
		else
			flags->modifier = L;
		break;
	}
	return (ptr);
}
/**
 * print_flags - prints the flags
 * @flags: struct containing formatting flags
 * *str: pointer to the format string
 * Return: number of characters printed
 */

int print_flags(flags_t *flags, char *str)
{
	int index = 0;

	switch (*str)
	{
	case ' ':
		index = flags->space = 1;
		break;
	case '-':
		index = flags->minus = 1;
		break;
	case '+':
		index = flags->plus = 1;
		break;
	case '#':
		index = flags->hash = 1;
		break;
	case '0':
		index = flags->zero = 1;
		break;
	}
	return (index);
}

/**
 * get_width - gets the width for a format string
 * @ptr: pointer to the format string
 * @flags: struct containing formatting flags
 * @arg: arguments passed
 * Return: ptr created.
 */

char *get_width(char *ptr, flags_t *flags, va_list arg)
{
	if (*ptr == '*')
	{
		flags->width = va_arg(arg, int);
		if (flags->width < 0)
		{
			flags->minus = 1;
			flags->width *= -1;
		}
		ptr++;
	}
	else
	{
		flags->width = _atoi(ptr);
		while (_isdigit(*ptr))
			ptr++;
	}
	return (ptr);
}
