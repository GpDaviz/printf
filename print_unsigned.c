#include "main.h"

/**
 * print_unsigned - Prints an unsigned integer.
 * @num: The unsigned integer to be printed.
 *
 * Return: The number of characters printed.
 */

int print_unsigned(unsigned int num)
{
	int count = 0;
	unsigned int divisor = 1;

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	while ((num / divisor) >= 10)
	{
		divisor *= 10;
	}

	while (divisor > 0)
	{
		_putchar((num / divisor) + '0');
		num %= divisor;
		divisor /= 10;
		count++;
	}

	return (count);
}
