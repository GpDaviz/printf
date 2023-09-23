#include "main.h"

/* PRINT CHAR *************************/

/**
 * print_char - Prints a character
 * @types: List a of arguments to get
 * @buffer: Buffer array to handle prints
 * @flags:  Checks active flags
 * @width: Width of argument
 * @precision: gets the Precision
 * @size: specifier size
 * Return: Number of chars printed
 */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char cha = va_arg(types, int);

	return (handle_write_char(cha, buffer, flags, width, precision, size));
}
/* PRINT A STRING *************************/
/**
 * print_string - Printing a string
 * @types: List a of arguments to get
 * @buffer: Buffer array to handle prints
 * @flags:  Checks active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: specifier size
 * Return: Number of strings printed
 */
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int lenx = 0, i;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[lenx] != '\0')
		lenx++;

	if (precision >= 0 && precision < lenx)
		lenx = precision;

	if (width > lenx)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], lenx);
			for (i = width - lenx; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - lenx; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], lenx);
			return (width);
		}
	}

	return (write(1, str, lenx));
}
/* PRINT PERCENT SIGN *************************/
/**
 * print_percent - Prints a percentage sign
 * @types: Lista of arguments to get
 * @buffer: Buffer array to handle prints
 * @flags: Checks active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: specifier size
 * Return: Number of chars printed
 */
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/* PRINT INT *************************/
/**
 * print_int - Print integers
 * @types: Lists of arguments to get
 * @buffer: Buffer array to handle prints
 * @flags: Checks active flags
 * @width: get widths.
 * @precision: Precision specification
 * @size: specifier size
 * Return: Number of chars printed
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int number;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	number = (unsigned long int)n;

	if (n < 0)
	{
		number = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (number > 0)
	{
		buffer[i--] = (number % 10) + '0';
		number /= 10;
	}

	i++;

	return (write_number(is_negative, i, buffer, flags, width, precision, size));
}

/* PRINT BINARY *************************/
/**
 * print_binary - function that prints an unsigned number
 * @types: Lists of arguments
 * @buffer: Buffer array to handle prints
 * @flags: Checks active flags
 * @width: get widths.
 * @precision: Precision specification
 * @size: Specifier size
 * Return: Numbers of char printed.
 */
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int n, s, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(types, unsigned int);
	s = 2147483648; /* (2 ^ 31) */
	a[0] = n / s;
	for (i = 1; i < 32; i++)
	{
		s /= 2;
		a[i] = (n / s) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
