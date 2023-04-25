#include "main.h"

/**
* print_integer - prints integers
* @args: argument passed
* @flags: struct flags
*/

int print_integer(va_list args, flags_t *flags)
{
	long num;

	if (flags->length)
	{
		num = va_arg(args, long);
	}
	else if (flags->height)
	{
		num = (short int)va_arg(args, int);
	}
	else
	{
		num = (int)va_arg(args, int);
	}

	return (print_num_op(convert_num(num, 10, 0, flags), flags));
	/* 10 is base 10 */ /* 0 is for unsigned */
}

/**
* print_ch - prints a character
* @args: argument passed
* @flags: struct flags
* Return: number of characters printed
*/

int print_ch(va_list args, flags_t *flags)
{
	unsigned int padding, total, char_printed;

	padding = 1;
	total = 0;
	char_printed = va_arg(args, int);

	if (flags->minus)
	{
		_putchar(char_printed);
		total++;
	}
	while (padding++ < flags->width)
	{
		_putchar(' ');
		total++;
	}
	if (!flags->minus)
	{
		_putchar(char_printed);
		total++;
	}

	return (total);
}

int print_string(va_list args, flags_t *flags)
{
	char *str;
	unsigned int padding, total, count, count2;

	str = va_arg(args, char *);
	padding = 0;
	total = 0;
	count = 0;

	(void)flags;
	if ((int)(!str))
		str = NULL_S;
	count2 = _strlen(str);
	padding = _strlen(str);

	if (flags->precision < padding)
		padding = flags->precision;
		count2 = flags->precision;

	if (flags->minus)
	{
		if (flags->precision != UINT_MAX)
		{
			for (count = 0; count < padding; count++)
				total += _putchar(*str++);
		}
		else
			total += puts_str(str);
	}
	while (count2++ < flags->width)
		total += _putchar(' ');

	if (!flags->minus)
	{
		if (flags->precision != UINT_MAX)
			for (count = 0; count < padding; count++)
				total += _putchar(*str++);
		else
			total += puts_str(str);
	}
	return (total);
}

/**
* print_percent - prints a percent sign
* @arg: argument passed
* @flags: struct flags
* Return: number of characters printed
*/

int print_percent(va_list arg, flags_t *flags)
{
	(void)arg;

	(void)flags;

	return (_putchar('%'));
}

/**
* print_custom - prints a custom format specifier
* @args: argument passed
* @flags: struct flags
* Return: number of characters printed
*/
int print_custom(va_list args, flags_t *flags)
{
	char *hex_va;
	char *str;
	int total = 0;

	str = va_arg(args, char *);

	if ((int)(!str))
	{
		return (puts_str(NULL_S));
	}
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			total += _putchar('\\');
			total += _putchar('x');
			hex_va = convert_num(*str, 16, 0, flags);
			/* 16 is base 16 */ /* 0 is for unsigned */
			if (!hex_va[1])
			{
				total += _putchar('0');
			}

			total += puts_str(hex_va);
		}
		else
		{
			total += _putchar(*str);
		}
	}
	return (total);
}
