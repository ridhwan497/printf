#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: character string
 * Return: number of characters printed
 * created by @ridhwan497 and @rafmury
 */

int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;
	char *str, *start;
	flags_t flags = INITIALIZE_FLAGS;

	va_start(args, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (str = (char *)format; *str; str++)
	{
		initialize_flags(&flags, args);
		if (*str != '%')
		{
			count += _putchar(*str);
			continue;
		}
		start = str;
		str++;
		while (print_flags(&flags, str)) /* while char at str is flag char */
		{
			str++; /* next char */
		}
		str = get_width(str, &flags, args);
		str = get_precision(str, &flags, args);
		if (get_modifier(str, &flags))
			str++;
		if (!handle_format_specifier(str))
			count += print_range(start, str,
				flags.length || flags.height ? str - 1 : 0);
		else
			count += format_function(str, args, &flags);
	}
	_putchar(-1);

	va_end(args);
	return (count);
}
