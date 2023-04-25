#include "main.h"

/**
 * print_unsigned - prints an unsigned integer in decimal, octal, or hexadecimal
 * @n: the unsigned integer to print
 * @base: the base to print the integer in (8 for octal, 10 for decimal, 16 for hexadecimal)
 * @uppercase: whether to print the hexadecimal letters in uppercase (1) or lowercase (0)
 *
 * Return: the number of characters printed
 */

int print_unsigned(unsigned int n, int base, char uppercase)
{
	int count, count2;
	char buff[BUFFER_SIZE];
	const char *digits;

	count = 0;
	digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";

  do {
    buff[count++] = digits[n % base];
    n /= base;
  } while (n > 0);

  /* print the buffer in reverse order */
  for (int count2 = count - 1; count2 >= 0; count2--) {
    _putchar(buff[count2]);
  }

  return count;
}
