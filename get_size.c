#include "main.h"
/**
 * get_size - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 *
 * Return: The size to cast the argument.
 */
int get_size(const char *format, int *i)
{
    int size = 0;

    switch (format[*i + 1])
    {
        case 'l':
            size = S_LONG;
            *i += 1;
            break;
        case 'h':
            size = S_SHORT;
            *i += 1;
            break;
        default:
            break;
    }

    return size;
}
