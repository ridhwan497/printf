#include "main.h"

/**
 * print_custom - prints a custom format specifier
 * @format: format specifier to be printed
 * @args: arguments to be printed
 * Return: number of characters printed
 */

int print_custom(const char *format, va_list args)
{
		int count = 0;

	if (*format == 'S')
	{
		char *str = va_arg(args, char *);
		if (str == NULL)
		{
			str = "(null)";
		}
		while (*str)
		{
			if (*str < 32 || *str >= 127)
			{
				count += _putchar('\\');
				count += _putchar('x');
				if (*str < 16)
				{
					count += _putchar('0');
				}
				count += print_unsigned((unsigned int)*str, 16, 1);
			}
			else
			{
				count += _putchar(*str);
			}
			str++;
		}
	}
	else
	{
		/* Handles unknown conversion specifier */
		count += _putchar('%');
		count += _putchar(*format);
	}

	return count;
}
