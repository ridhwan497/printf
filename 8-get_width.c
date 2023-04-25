#include "main.h"

/**
 * get_width - handles the width of non custom format specifiers
 * @format: format string
 * @q: index of format string
 * Return: width
 */

int get_width(const char *format, int *q)
{
	int p, curr_q;
	int width = 0;

	for (curr_q = *q + 1; format[curr_q] != '\0'; curr_q++)
	{
		for (p = 0; p <= 9; p++)
			if (format[curr_q] == p + '0')
			{
				width = width * 10 + p;
				break;
			}
		if (p == 10)
			break;
	}
	*q = curr_q - 1;
	return (width);
}
