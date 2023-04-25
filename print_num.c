#include "main.h"

/**
 * print_octal_number - prints an octal number
 * @args: argument passed
 * @flags: struct flags
 */
int print_octal_number(va_list args, flags_t *flags)
{
	unsigned int num;
	char *octal_num;
	int count = 0;

	if (flags->height)
	{
		num = (unsigned short int)va_arg(args, unsigned int);
	}
	else if (flags->length)
	{
		num = (unsigned long)va_arg(args, unsigned int);
	}
	else
	{
		num = (unsigned int)va_arg(args, unsigned int);
	}
	octal_num = convert_num(num, 8, flags, UNSIGNED);

	if (flags->hash && num)
	{
		*--octal_num = '0';
	}
	count += puts_str(octal_num);
	free(octal_num);
	return (count);
}

/**
 * print_hex_lowercase - prints a hexadecimal number in lowercase
 * @args: argument passed
 * @flags: struct flags
 */
int print_hex_lowercase(va_list args, flags_t *flags)
{
	unsigned int num;
	char *hex_num;
	int count = 0;

	if (flags->height)
	{
		num = (unsigned short int)va_arg(args, unsigned int);;
	}
	else if (flags->length)
	{
		num = (unsigned long int)va_arg(args, unsigned int);
	}
	else
	{
		num = (unsigned int)va_arg(args, unsigned int);
	}
	hex_num = convert_num(num, 16, flags, UNSIGNED | LOWERCASE);

	if (flags->hash && num)
	{
		*--hex_num = 'x';
		*--hex_num = '0';
	}
	count += puts_str(hex_num);
	free(hex_num);
	return (count);
}

/**
 * print_hex_uppercase - prints a hexadecimal number in uppercase
 * @args: argument passed
 * @flags: struct flags
 */
int print_hex_uppercase(va_list args, flags_t *flags)
{
	unsigned int num;
	char *hex_num;
	int count = 0;

	if (flags->height)
	{
		num = (unsigned short int)va_arg(args, unsigned int);
	}
	else if (flags->length)
	{
		num = va_arg(args, unsigned long int);
	}
	else
	{
		num = va_arg(args, unsigned int);
	}
	hex_num = convert_num(num, 16, flags, UNSIGNED);

	if (flags->hash && num)
	{
		*--hex_num = 'X';
		*--hex_num = '0';
	}
	count += puts_str(hex_num);
	free(hex_num);
	return (count);	
}

/**
 * print_binary - prints a binary number
 * @args: argument passed
 * @flags: struct flags
 */
int print_binary(va_list args, flags_t *flags)
{
	unsigned int num;
	char *binary_num;
	int count = 0;

	if (flags->height)
	{
		num = (unsigned short int)va_arg(args, unsigned int);
	}
	else if (flags->length)
	{
		num = va_arg(args, unsigned long int);
	}
	else
	{
		num = va_arg(args, unsigned int);
	}
	binary_num = convert_num(num, 2, flags,UNSIGNED);

	count += puts_str(binary_num);
	free(binary_num);
	return (count);
}
