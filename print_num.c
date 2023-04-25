#include "main.h"

/**
 * print_octal_number - prints an octal number
 * @args: argument passed
 * @flags: struct flags
 * Return: number of characters printed
 */
int print_octal_number(va_list args, flags_t *flags)
{
	unsigned long num;
	char *octal_num;
	int count = 0;

	if (flags->height)
	{
		num = (unsigned short int)va_arg(args, unsigned int);
	}
	else if (flags->length)
	{
		num = (unsigned long)va_arg(args, unsigned long);
	}
	else
	{
		num = (unsigned int)va_arg(args, unsigned int);
	}
	octal_num = convert_num(num, 8, UNSIGNED, flags);

	if (flags->hash && num)
	{
		*--octal_num = '0';
	}

	flags->unsign = 1;
	count += print_num_op(octal_num, flags);

	return (count);
}

/**
 * print_hex_lowercase - prints a hexadecimal number in lowercase
 * @args: argument passed
 * @flags: struct flags
 * Return: number of characters printed
 */
int print_hex_lowercase(va_list args, flags_t *flags)
{
	unsigned long num;
	char *hex_num;
	int count = 0;

	if (flags->height)
	{
		num = (unsigned short int)va_arg(args, unsigned int);
	}
	else if (flags->length)
	{
		num = (unsigned long)va_arg(args, unsigned long);
	}
	else
	{
		num = (unsigned int)va_arg(args, unsigned int);
	}
	hex_num = convert_num(num, 16, UNSIGNED | LOWERCASE, flags);

	if (flags->hash && num)
	{
		*--hex_num = 'x';
		*--hex_num = '0';
	}
	flags->unsign = 1;
	count += print_num_op(hex_num, flags);

	return (count);
}

/**
 * print_hex_uppercase - prints a hexadecimal number in uppercase
 * @args: argument passed
 * @flags: struct flags
 * Return: number of characters printed
 */
int print_hex_uppercase(va_list args, flags_t *flags)
{
	unsigned long num;
	char *hex_num;
	int count = 0;

	if (flags->height)
	{
		num = (unsigned short int)va_arg(args, unsigned int);
	}
	else if (flags->length)
	{
		num = (unsigned long)va_arg(args, unsigned long);
	}
	else
	{
		num = (unsigned int)va_arg(args, unsigned int);
	}
	hex_num = convert_num(num, 16, UNSIGNED, flags);

	if (flags->hash && num)
	{
		*--hex_num = 'X';
		*--hex_num = '0';
	}
	flags->unsign = 1;

	count += print_num_op(hex_num, flags);

	return (count);
}

/**
 * print_binary - prints a binary number
 * @args: argument passed
 * @flags: struct flags
 * Return: number of characters printed
 */
int print_binary(va_list args, flags_t *flags)
{
	unsigned int num;
	char *binary_num;
	int count = 0;

	binary_num = convert_num(num, 2, UNSIGNED, flags);
	num = va_arg(args, unsigned int);

	if (flags->hash && num)
	{
		*--binary_num = 'b';
		*--binary_num = '0';
	}
	flags->unsign = 1;
	count += print_num_op(binary_num, flags);

	return (count);
}
