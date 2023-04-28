#include "main.h"
/**
 * _printf - produces output according to a format
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;
	char *p = (char *)format;
	char buffer[BUFF_SIZE] = {0};
	int buffer_len = 0;
	va_start(args, format);
	while (*p)
	{
		if (*p != '%')
		{
			buffer[buffer_len++] = *p;
			if (buffer_len == BUFF_SIZE)
			{
				count += write(STDOUT_FILENO, buffer, buffer_len);
				buffer_len = 0;
			}
			p++;
			count++;
			continue;
		}
		p++;
		if (*p == '%')
		{
			buffer[buffer_len++] = *p;
			if (buffer_len == BUFF_SIZE)
			{
				count += write(STDOUT_FILENO, buffer, buffer_len);
				buffer_len = 0;
			}
			p++;
			count++;
			continue;
		}
		int width = -1, precision = -1;
		while (*p && is_flag(*p))
			update_flag(*p++, &width, &precision);
		if (*p && isdigit(*p))
			width = extract_number(&p);
		if (*p == '.')
		{
			p++;
			if (*p && isdigit(*p))
				precision = extract_number(&p);
			else
				precision = 0;
		}
		char specifier = *p++;
		switch (specifier)
		{
			case 'c':
				count += handle_char(buffer, &buffer_len, va_arg(args, int));
				break;
			case 's':
				count += handle_string(buffer, &buffer_len, va_arg(args, char *), precision);
				break;
			case 'd':
			case 'i':
				count += handle_integer(buffer, &buffer_len, va_arg(args, int), width, precision);
				break;
			case 'u':
				count += handle_unsigned(buffer, &buffer_len, va_arg(args, unsigned int), width, precision);
				break;
			case 'o':
				count += handle_octal(buffer, &buffer_len, va_arg(args, unsigned int), width, precision);
				break;
			case 'x':
				count += handle_hex(buffer, &buffer_len, va_arg(args, unsigned int), width, precision, 0);
				break;
			case 'X':
				count += handle_hex(buffer, &buffer_len, va_arg(args, unsigned int), width, precision, 1);
				break;
			case 'p':
				count += handle_pointer(buffer, &buffer_len, va_arg(args, void *));
				break;
			default:
				buffer[buffer_len++] = '%';
				if (buffer_len == BUFF_SIZE)
				{
					count += write(STDOUT_FILENO, buffer, buffer_len);
					buffer_len = 0;
				}
				if (*p)
				{
					buffer[buffer_len++] = *p++;
					if (buffer_len == BUFF_SIZE)
					{
						count += write(STDOUT_FILENO, buffer, buffer_len);
						buffer_len = 0;
					}
				}
				count++;
				break;
		}
	}
	if (buffer_len > 0)
		count += write(STDOUT_FILENO, buffer, buffer_len);
	va_end(args);
	return count;
}
