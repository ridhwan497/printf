#include "main.h"

/**
 * print_reverse - prints a string in reverse
 * @s: string to be printed
 * Return: number of characters printed
 */

int print_reverse(char *s)
{
	int count;
	int len;

	count = 0;
	len = 0;

	while (s[len] != '\0')
	{
		len++;
	}

	while (len > 0)
	{
		count += _putchar(s[--len]);
	}

	return (count);
}
