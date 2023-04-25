#include "main.h"

/**
 * handle_format_specifier - handles format specifiers
 * @ptr: pointer to the format string
 * Return: number of characters printed
 */

int (*handle_format_specifier(char *ptr))(va_list args, flags_t *flags)
{
	int index = 0;
	print_t print[] = {
		{"c", print_ch},
		{"s", print_string},
		{"d", print_integer},
		{"i", print_integer},
		{"b", print_binary},
		{"u", unsigned_num},
		{"o", print_octal_number},
		{"x", print_hex_lowercase},
		{"p", print_address},
		{"X", print_hex_uppercase},
		{"r", print_reverse},
		{"R", print_rot13},
		{"S", print_custom},
		{"%", print_percent},
		{NULL, NULL}
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

	return (0);
}

/**
 * get_modify - gets the modifier for a format string
 * @ptr: pointer to the format string
 * @flags: struct containing formatting flags
 * Return: ptr created.
 */

int get_modify(char *ptr, flags_t *flags)
{
	int index;

	index = 0;

	switch (*ptr)
	{
		case 'h':
			index = flags->height = 1;
			break;
		case 'l':
			index = flags->length = 1;
			break;
	}
	return (index);
}
/**
 * print_flags - prints the flags
 * @flags: struct containing formatting flags
 * @str: pointer to the format string
 * Return: number of characters printed
 */

int print_flags(char *str, flags_t *flags)
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
 * get_width - gets the width of string
 * @ptr: pointer to string
 * @flags: struct containing formatting flags
 * @arg: arguments passed
 * Return: ptr created.
 */

char *get_width(char *ptr, flags_t *flags, va_list arg)
{
	int index = 0;

	if (*ptr == '*')
	{
		index = va_arg(arg, int);
		ptr++;
	}
	else
	{
		while (_isdigit(*ptr))
			index = index * 10 + (*ptr++ - '0');
	}
	flags->width = index;

	return (ptr);
}
