#include "main.h"
#include <stdio.h>

/**
 * print_binary - Prints an integer in binary format.
 * @num: The integer to be printed.
 *
 * Return: The number of characters printed.
 */
int print_binary(int num)
{
	int count = 0;
	int binary[32];  /* Assuming 32-bit integers */
	int index = 0;
	int i; /* Move the declaration here */

	if (num == 0)
    {
        _putchar('0');
        return 1;
    }

    if (num < 0)
    {
        _putchar('-');
        count++;
        num = -num;
    }

    while (num > 0)
    {
        binary[index++] = num % 2;
        num /= 2;
    }

    for (i = index - 1; i >= 0; i--) /* Use 'i' in the loop */
    {
        _putchar(binary[i] + '0');
        count++;
    }

    return count;
}
