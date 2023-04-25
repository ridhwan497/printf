#include "main.h"

/**
 * print_rot13 - prints a string in rot13 
 * rot13 is a simple letter substitution cipher that 
 * replaces a letter with the letter 13 letters after it in the alphabet.
 * @s: string to be printed
 * Return: number of characters printed
 */

int print_rot13(char *s)
{
	int count;
	int i;
	char *alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char *rot13 = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	count = 0;
	i = 0;

	while (s[i] != '\0')
	{
		int j;

		j = 0;
		while (alpha[j] != '\0')
		{
			if (s[i] == alpha[j])
			{
				count += _putchar(rot13[j]);
				break;
			}
			j++;
		}
		if (alpha[j] == '\0')
		{
			count += _putchar(s[i]);
		}
		i++;
	}

	return (count);	
}
