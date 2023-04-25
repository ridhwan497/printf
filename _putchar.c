#include "main.h"

/**
 * _putchar - writes char to output
 * @c: type int
 * Return: 1 success.
 */

int _putchar(int c)
{
	static int count; /* counter for number of characters printed */
	static char buffer[BUFFER_SIZE]; /* buffer to store characters */

	if (c == -1 || count >= BUFFER_SIZE)
	{
		write(1, buffer, count);
		count = 0;
	}
	if (c != FLUSH)
	{
		buffer[count] = c;
		count++;
	}
	return (1);
}

/**
 * puts_str - prints a string with /n
 * @s - string to print
 * Return: number of characters printed
 */

int puts_str(char *s)
{
	char *ptr;

	ptr = s;

	while (*s)
	{
		_putchar(*s++);
	}
	_putchar('\n');
	return (ptr - s);
}
