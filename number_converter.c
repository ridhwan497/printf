#include "main.h"
char *convert_num(long int number, int base, flags_t *flags, int parameters);
/**
 * unsigned_num - prints an unsigned number
 * @args: arguments passed to _printf
 * @flags: struct containing formatting flags
 * Return: number of characters printed
 */

int unsigned_num(va_list args, flags_t *flags)
{
	unsigned int num;
	char *str;
	int count = 0;

	num = va_arg(args, unsigned int);
	str = convert_num(num, 10, flags, UNSIGNED);
	count += puts_string(str);
	return (count);
}

/**
 * convert_num - converts a number from base 10 to another base
 * it acts like the itoa function in the standard library
 * @n: number to convert
 * @base: base to convert to
 * @flags: struct containing formatting flags
 * @parameters: struct containing information about the string to print
 * Return: pointer to the converted string
 */

char *convert_num(long int number, int base, flags_t *flags, int parameters)
{
	static char buffer[50];
	char *ptr = &buffer[49];
	unsigned long index = number;
	const char *digit = (parameters & LOWERCASE) ? "0123456789abcdef" : "0123456789ABCDEF"; /* digits for hexadecimal */

	if (!(parameters & UNSIGNED) && number < 0)
	{
		index = -number;
		*--ptr = '-';
	}

	*ptr = digit[index % base];
	index /= base;

	while (index > 0)
	{
		*--ptr = digit[index % base];
		index /= base;
	}

	return (ptr);
}

/**
 * print_address - prints an address
 * @args: arguments passed to _printf
 * @flags: struct containing formatting flags
 * Return: number of characters printed
 */

int print_address(va_list args, flags_t *flags)
{
	unsigned long int address;
	char *str;
	int count = 0;

	address = va_arg(args, unsigned long int);
	str = convert_num(address, 16, flags, LOWERCASE | UNSIGNED);
	count += puts_str("0x");
	count += puts_str(str);
	return (count);
}
