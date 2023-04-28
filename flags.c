#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: pointer to current index in the format string
 *
 * Return: Flags:
 */
int get_flags(const char *format, int *i)
{
    int flags = 0;
    int curr_i = *i + 1;
    bool stop = false;
    
    while (!stop && format[curr_i] != '\0') {
        switch (format[curr_i]) {
            case '-': flags |= F_MINUS; break;
            case '+': flags |= F_PLUS; break;
            case '0': flags |= F_ZERO; break;
            case '#': flags |= F_HASH; break;
            case ' ': flags |= F_SPACE; break;
            default: stop = true; break;
        }
        if (!stop) {
            curr_i++;
        }
    }
    *i = curr_i - 1;

    return flags;
}
