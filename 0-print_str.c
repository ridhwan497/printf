#include "main.h"

/**
 * print_char - prints a character
 * @arg: arguments list
 * @specifier: format specifier
 *
 * Return: number of characters printed
 */
int print_char(va_list arg, const char specifier)
{
	char c = va_arg(arg, int);
	int count = 0;

	if (specifier == 'c')
	{
		count += _putchar(c);
	}

	return (count);
}

/**
 * print_str - prints a string
 * @arg: arguments list
 * @specifier: format specifier
 *
 * Return: number of characters printed
 */
int print_str(va_list arg, const char specifier)
{
	char *str;
	int count = 0;

	if (specifier == 's')
	{
		str = va_arg(arg, char *);
		if (str == NULL)
		{
			str = "(null)";
		}
		count += print_str(str, specifier);
	}

	return (count);
}

/**
 * print_string - prints a string
 * @arg: arguments list
 * @specifier: format specifier
 * Return: number of characters printed
 */

int print_string(va_list arg, const char specifier)
{
    char *str;
    int count = 0;

    if (specifier == 'c')
    {
        count += print_char(va_arg(arg, int), specifier);
    }
    else if (specifier == 's')
    {
        str = va_arg(arg, char *);
        if (str == NULL)
        {
            str = "(null)";
        }
        count += print_str(str, specifier);
    }
    else if (specifier == '%')
    {
        count += _putchar('%');
    }

    return (count);
}
