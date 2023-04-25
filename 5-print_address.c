#include "main.h"

/**
 * print_address - prints the address of a pointer
 * @a: pointer to be printed
 * Return: number of characters printed
 */

int print_address(void *a)
{
	int count;
	uintptr_t address; /*uintptr_t is unsigned int*/

	count = 0;
	address = (uintptr_t)a;

	count += _putchar('0');
	count += _putchar('x');
	count += print_unsigned(address, 16, 1);

	return (count);
}
