#include "main.h"

/**
*get_flags - Function that calculates active flags
*@format: Formatted string
* @p: parameter p
* by ridhwan497 and rafmury
* Return: Flags
*/
int get_flags(const char *format, int *q)
{
    /* - + 0 ' ' # */
    /* 1 2 4 8 16*/
    int p, curr_q;
    int flags = 0;
    const char FLAGS_CH[] = {'-', '+','0', ' ','#', '\0'};
    const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_SPACE, F_HASH, 0};

    for (curr_q = *q + 1; format[curr_q] != '\0'; curr_q++)
    {
        for (p = 0; FLAGS_CH[p] != '\0'; p++)
            if (format[curr_q] == FLAGS_CH[p])
            {
                flags |= FLAGS_ARR[p];
                break;
            }
        if (FLAGS_CH[p] == 0)
            break;
    }
    *q = curr_q - 1;
    return (flags);
}
