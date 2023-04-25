#include "main.h"

/**
 * print_num_op - prints an integer with options
 * @str: string to print
 * @flags: struct flags
 * Return: number of characters printed
 */

int print_num_op(char *str, flags_t *flags)
{
	unsigned int index;
	int negative;

	index = _strlen(str); /* get length of string */

	negative = (!flags->unsign && *str == '-') ? 1 : 0; /* check if negative */

	if (!flags->precision && *str == '0' && !str[1])
		str = "";
	if (negative)
	{
		str++;
		index--;
	}
	if (flags->precision != UINT_MAX) /* if precision is set */
		while (index++ < flags->precision)
			*--str = '0';
	if (negative)
	{
		*--str = '-';
	}
	if (!flags->minus)
		return (print_right(str, flags));
	else
		return (print_left(str, flags));
}

/**
 * print_left - prints number to the left
 * @str: string to print
 * @flags: struct flags
 * Return: number of characters printed
 */
int print_left(char *str, flags_t *flags)
{
	unsigned int index, count;
	int negative1, negative2;
	char ch;

	count = 0;
	index = _strlen(str);
	ch = ' ';

	if (flags->zero && !flags->minus)
		ch = '0';

	negative1 = (!flags->unsign && *str == '-');
	negative2 = (!flags->unsign && *str == '-');

	if (negative1 && index < flags->width && ch == '0' && !flags->minus)
		str++;
	else
		negative1 = 0;

	if (flags->plus && !negative2 && !flags->unsign)
		count += _putchar('+'), index++;

	else if (flags->space && !negative2 && !flags->unsign)
		count += _putchar(' '), index++;

	count += puts_str(str);

	while (index++ < flags->width)
		count += _putchar(ch);

	return (count);
}

/**
 * print_right - prints number to the right
 * @str: string to print
 * @flags: struct flags
 * Return: number of characters printed
 */

int print_right(char *str, flags_t *flags)
{
	unsigned int index, count;
	int negative1, negative2;
	char ch;

	count = 0;
	index = _strlen(str);
	ch = ' ';
	if (flags->zero && !flags->minus)
		ch = '0';
	negative1 = negative2 = (!flags->unsign && *str == '-');

	if (negative1 && index < flags->width && ch == '0' && !flags->minus)
		str++;
	else
		negative1 = 0;

	if ((flags->plus && !negative2) ||
		(!flags->plus && flags->space && !negative2))
		index++;
	if (negative1 && ch == '0')
		count += _putchar('-');
	if (flags->plus && !negative2 && ch == '0' && !flags->unsign)
		count += _putchar('+');
	else if (!flags->plus && flags->space && !negative2
		&& !flags->unsign && flags->zero)
		count += _putchar(' ');
	while (index++ < flags->width)
		count += _putchar(ch);
	if (negative1 && ch == ' ')
		count += _putchar('-');
	if (flags->plus && !negative2 && ch == ' ' && !flags->unsign)
		count += _putchar('+');
	else if (!flags->plus && flags->space && !negative2 && !flags->unsign
		&& !flags->zero)
		count += _putchar(' ');
	count += puts_str(str);
	return (count);
}

/**
 * _strlen - returns the length of a string
 * @str: string to check
 * Return: length of string
 */

int _strlen(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
		;
	return (i);
}

/**
 * _isdigit - checks if a character is a digit
 * @c: character to check
 * Return: 1 if digit, 0 otherwise
 */

int _isdigit(int ch)
{
	return (ch >= '0' && ch <= '9');
}
