#include "main.h"

/**
 * print_number - prints an integer
 * handles the specifiers d and i
 * @n: integer to be printed
 * Return: number of characters printed
 */

int print_number(va_list arg, const char specifier)
{
    int n = va_arg(arg, int);
    int count = 0;

    if (specifier == 'd' || specifier == 'i')
    {
        if (n < 0)
        {
            count += _putchar('-');
            n = -n;
        }

        if (n / 10)
        {
            count += print_number(arg, specifier);
        }

        count += _putchar((n % 10) + '0');
    }

    return (count);
}
