#include "main.h"

/**
 * print_binary - prints the binary representation of a number
 * @n: number to be printed
 * Return: number of characters printed
 */

int print_binary(unsigned long int n)
{
	int count;

	count = 0;

	if (n == 0)
	{
		count += _putchar('0');
		return (count);
	}

	if (n > 1)
	{
		count += print_binary(n >> 1);
	}

	count += _putchar((n & 1) + '0');

	return (count);
}
