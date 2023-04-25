#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: 1 success.
 */

int _putchar(int c)
{
	static int count; /* counter for number of characters printed */
	static char buffer[BUFFER_SIZE]; /* buffer to store characters */

	if (c == -1 || count == BUFFER_SIZE)
	{
		write(1, buffer, count);
		count = 0;
	}
	if (c != -1)
	{
		buffer[count] = c;
		count++;
	}
	return (1);
}

/**
 * puts_str - prints a string with /n
 * @str - string to print
 * Return: number of characters printed
 */

int puts_str(char *str)
{
	char *ptr;
	int count = 0;

	if (str == NULL)
		str = "(null)";
	ptr = str;
	while (*ptr)
	{
		_putchar(*ptr);
		ptr++;
		count++;
	}
	return (count);
}
