#include "main.h"

char *convert_num(long int number, int base, int parameters, flags_t *flags);

/**
 * unsigned_num - prints an unsigned number
 * @args: arguments passed to _printf
 * @flags: struct containing formatting flags
 * Return: number of characters printed
 */

int unsigned_num(va_list args, flags_t *flags)
{
	unsigned long num;

	if (flags->length)
		num = (unsigned long)va_arg(args, unsigned long);
	else if (flags->height)
		num = (unsigned short int)va_arg(args, unsigned int);
	else
		num = (unsigned int)va_arg(args, unsigned int);

	flags->unsign = 1;

	return (print_num_op(convert_num(num, 10, UNSIGNED, flags), flags));
}

/**
 * convert_num - converts a number from base 10 to another base
 * it acts like the itoa function in the standard library
 * @number: number to convert
 * @base: base to convert to
 * @flags: struct containing formatting flags
 * @parameters: struct containing information about the string to print
 * Return: pointer to the converted string
 */

char *convert_num(long int number, int base, int parameters, flags_t *flags)
{
	static char buff[50];
	static char *a;
	char *str;
	unsigned long num;
	char sign_ch;

	num = number;
	sign_ch = 0;

	(void)flags;

	if (!(parameters & UNSIGNED) && number < 0)
	{
		num = -number;
		sign_ch = '-';

	}
	a = parameters & LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	/* 16 chars */

	str = &buff[49]; /* last char */

	*str = '\0'; /* null terminate */

	do	{
		*--str = a[num % base];
		num /= base;
	} while (num != 0);

	if (sign_ch)
	{
		*--str = sign_ch;
	}

	return (str);
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

	address = va_arg(args, unsigned long int);

	if (!address)
	{
		return (puts_str("(nil)"));
	}

	str = convert_num(address, 16, LOWERCASE | UNSIGNED, flags);

	*--str = '0';
	*--str = 'x';

	return (print_num_op(str, flags));
}
