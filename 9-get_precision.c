#include "main.h"

/**
 * get_precision - gets the precision of a format specifier
 * @format: format string
 * @q: index of format string
 * Return: precision
 */

int get_precision(const char *format, int *q)
{
	int p, curr_q;
	int precision = 0;

	for (curr_q = *q + 1; format[curr_q] != '\0'; curr_q++)
	{
		for (p = 0; p <= 9; p++)
			if (format[curr_q] == p + '0')
			{
				precision = precision * 10 + p;
				break;
			}
		if (p == 10)
			break;
	}
	*q = curr_q - 1;

	return (precision);
}
