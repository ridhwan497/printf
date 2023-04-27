#include "main.h"

/**
 * print_range - prints str range of adresses of type character
 * @begin: begining of the range
 * @end: end of the range
 * @excempt: adresses to not print
 * Return: number of characters printed
 */

int print_range(char *begin, char *end, char *excempt)
{
	int count = 0;

	while (begin <= end)
	{
		if (begin != excempt)
		{
			count += _putchar(*begin);
		}
		begin++;
	}
	free(begin);
	return (count);
}

/**
 * print_reverse - prints str string in reverse
 * @args: argument passed
 * @flags: struct flags
 * Return: number of characters printed
 */

int print_reverse(va_list args, flags_t *flags)
{
	char *str;
	int count = 0;
	int i;

	str = va_arg(args, char *);
	(void)flags;

	if (str)
	{
		for (i = 0; *str; str++)
		{
			i++;
		}
		str--;

		for (; i > 0; i--, str--)
		{
			count += _putchar(*str);
		}
	}
	free (str);
	return (count);
}

/**
 * print_rot13 - prints string in rot13
 * rot13 is a simple letter substitution cipher that replaces a letter
 * with the letter 13 letters after it in the alphabet.
 * @args: argument passed
 * @flags: struct flags
 * Return: number of characters printed
 */

int print_rot13(va_list args, flags_t *flags)
{
	int count;
	int count2;
	int index;
	char rot_array[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
	char *str;

	str = va_arg(args, char *);
	count = 0;
	count2 = 0;
	index = 0;

	(void)flags;

	while (str[count2])
	{
		if ((str[count2] >= 'A' && str[count2] <= 'Z')
		    || (str[count2] >= 'a' && str[count2] <= 'z'))
		{
			index = str[count2] - 65;
			count += _putchar(rot_array[index]);
		}
		else
			count += _putchar(str[count2]);
		count2++;
	}
	free(str);
	return (count);
}
