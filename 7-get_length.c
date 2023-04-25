#include "main.h"

/**
 * get_length - handles the length modifier of non custom format specifiers
 * @format: format string
 * @q: index of format string
 * Return: length modifier
 */

int get_length(const char *format, int *q)
{
	int p, curr_q;
	int length = 0;
	const char LENGTH_CH[] = {'h', 'l', 'L', '\0'};
	const int LENGTH_ARR[] = {L_H, L_L, L_LL, 0};

	for (curr_q = *q + 1; format[curr_q] != '\0'; curr_q++)
	{
		for (p = 0; LENGTH_CH[p] != '\0'; p++)
			if (format[curr_q] == LENGTH_CH[p])
			{
				length |= LENGTH_ARR[p];
				break;
			}
		if (LENGTH_CH[p] == 0)
			break;
	}
	*q = curr_q - 1;
	return (length);
}
