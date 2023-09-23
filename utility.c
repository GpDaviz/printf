#include "main.h"

/**
 * is_printable - checks if a char is a printable kind
 * @c: Character to be evaluated.
 * Return: 1 if c is printable, 0 otherwise
 */

int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - concatenates ascci in hexadecimal code to buffer
 * @buffer: the array of character.
 * @i: the index at which to start appending.
 * @ascii_code: ASSCI CODE.
 * Return: three (3)
 */

int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map[ascii_code / 16];
	buffer[i] = map[ascii_code % 16];

	return (3);
}

/**
 * is_digit - Checks if a character is a digit
 * @c: Character to be check
 * Return: 1 if c is a digit, else 0
 */

int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - Puts a number to the specified size
 * @num: Number to be casted to size.
 * @size: Number that indicates the type to be casted.
 * Return: Casted value of number
 */

long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - Puts a number to the specified size
 * @num: Number to be casted to size
 * @size: Number indicates the type to be casted
 * Return: Casted value of number
 */

long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
