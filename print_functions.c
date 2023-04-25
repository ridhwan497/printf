#include "main.h"

/**
* print_integer - prints integers
* @args: argument passed
* @flags: struct flags
*/

int print_integer(va_list args, flags_t *flags)
{
	long int num;
	char *int_num;
	int count = 0;

	if (flags->height)
	{
		num = (unsigned short int)va_arg(args, unsigned int);
	}
	else if (flags->length)
	{
		num = va_arg(args, long int);
	}
	else
	{
		num = va_arg(args, int);
	}
	int_num = convert_num(num, 10, 0, flags);
	count += puts_str(int_num);
	free(int_num);
	return (count);
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
	if (str == NULL)
		str = "(null)";
	
	count2 = padding = strlen(str);

	if (flags->precision < padding)
		count2 = flags->precision;
	
	if (flags->minus)
	{
		while (count2--)
		{
			_putchar(*str);
			str++;
			total++;
		}
	}
	else
	{
		total += puts_str(str);
	}
	while (padding-- > count2)
	{
		_putchar(' ');
		total++;
	}
	if (!flags->minus)
	{
		while (count2--)
		{
			_putchar(*str);
			str++;
			total++;
		}
	}
	else
	{
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
	unsigned int padding, total;

	padding = 1;
	total = 0;
	(void)arg;

	if (flags->minus)
	{
		_putchar('%');
		total++;
	}
	while (padding++ < flags->width)
	{
		_putchar(' ');
		total++;
	}
	if (!flags->minus)
	{
		_putchar('%');
		total++;
	}
	return (total);
}

/**
* print_custom - prints a custom format specifier
* @args: argument passed
* @flags: struct flags
* Return: number of characters printed
*/
int print_custom(va_list args, flags_t *flags)
{
	int *hex_va;
	char *str;
	int total = 0;

	if ((int)(!str))
		return (puts_str(NULL_S));
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			total += puts_str('\\');
			total += puts_str('x');
			hex_va = convert_num(*str, 16, 0, flags);
			if (!hex_va[1])
				total += puts_str('0');
			total += _putchar(hex_va);
		}
		else
		{
			total += _putchar(*str);
		}
	}
	return (total);
}
