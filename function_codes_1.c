#include "main.h"

/* PRINT UNSIGNED NUMBER *************************/
/**
 * print_unsigned -function that prints an unsigned numbers
 * @types: Lists of arguments
 * @buffer: Buffer array to handle prints
 * @flags: Checks active flags
 * @width: get widths
 * @precision: Precision specification
 * @size: Specifier size
 * Return: Number of num printed.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int n = va_arg(types, unsigned long int);

	n = convert_size_unsgnd(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (n > 0)
	{
		buffer[i--] = (n % 10) + '0';
		n /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * print_octal - Prints number in octal notation
 * @types: Lists of arguments
 * @buffer: Buffer array to handle prints
 * @flags: Checks active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Specifier size
 * Return: Number of num printed
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int n = va_arg(types, unsigned long int);
	unsigned long int init_num = n;

	UNUSED(width);

	n = convert_size_unsgnd(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (n > 0)
	{
		buffer[i--] = (n % 8) + '0';
		n /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/* PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * print_hexadecimal - Prints number in hexadecimal notation
 * @types: Lists of arguments
 * @buffer: Buffer array to handle prints
 * @flags: Checks active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Specifier size
 * Return: Numbers printed
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * print_hexa_upper - Prints numbers in upper hexadecimal
 * @types: Lists of arguments
 * @buffer: Buffer array to handle prints
 * @flags: Checks active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Specifier size
 * Return: Number of all chars printed
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/* PRINT HEXX NUM IN LOWER OR UPPER **************/
/**
 * print_hexa - function that  prints hexadecimal number in lower & upper
 * @types: Lists of arguments
 * @map_to: Array of values to map with
 * @buffer: Buffer array to handle prints
 * @flags: Checks for active flags
 * @flag_ch: Checks active flags again
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars has been printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int n = va_arg(types, unsigned long int);
	unsigned long int init_num = n;

	UNUSED(width);

	n = convert_size_unsgnd(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (n > 0)
	{
		buffer[i--] = map_to[n % 16];
		n /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
