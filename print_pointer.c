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
	return (count);
}

/**
 * print_pointer - prints str pointer
 * @args: argument passed
 * @flags: struct flags
 * Return: number of characters printed
 */

int print_pointer(va_list args, flags_t *flags)
{
	char *pointer;
	int count = 0;

	(void)flags;
	pointer = va_arg(args, char *);
	count += puts_str("0x");
	count += print_range(pointer, pointer + 7, pointer + 4);
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
	return (count);
}

/**
 * print_rot13 - prints string in rot13
 * @args: argument passed
 * @flags: struct flags
 * Return: number of characters printed
 */

int print_rot13(va_list args, flags_t *flags)
{
	int count;
	int i, index;
	char rot_array[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
	char *str = va_arg(args, char *);

	count = 0;
	i = 0;
	index = 0;

	(void)flags;

	while (str[i]) 
	{
		if ((str[i] >= 'A' && str[i] <= 'Z')
		    || (str[i] >= 'a' && str[i] <= 'z'))
		{
			index = str[i] - 65;
			count += _putchar(rot_array[index]);
		}
		else
			count += _putchar(str[i]);
		i++;
	}
	return (count);
}
