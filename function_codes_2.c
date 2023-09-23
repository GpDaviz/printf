#include "main.h"

/* PRINT POINTER ******************/
/**
 * print_pointer - Prints the content of a pointer
 * @types: Lists of arguments
 * @buffer: Buffer array to handle prints
 * @flags: Checks active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Specifier size
 * Return: Number of chars has been printed.
 */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1; /* length=2, for '0x' */
	unsigned long n_add;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	n_add = (unsigned long)addrs;

	while (n_add > 0)
	{
		buffer[ind--] = map_to[n_add % 16];
		n_add /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_c = '+', length++;
	else if (flags & F_SPACE)
		extra_c = ' ', length++;

	ind++;

	return (write_pointer(buffer, ind, length,
		width, flags, padd, extra_c, padd_start));
}

/* PRINT NON PRINTABLE *************************/
/**
 * print_non_printable - Prints ascii codes of  printable chars
 * @types: Lists of arguments
 * @buffer: Buffer array to handle prints
 * @flags: Checks active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Specifier size
 * Return: Number of chars has been printed
 */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = 0, off = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			buffer[i + off] = str[i];
		else
			off += append_hexa_code(str[i], buffer, i + off);

		i++;
	}

	buffer[i + off] = '\0';

	return (write(1, buffer, i + off));
}

/* PRINT REVERSE *************************/
/**
 * print_reverse - Prints string in reverse.
 * @types: Lists of arguments
 * @buffer: Buffer array to handle print
 * @flags: Checks for active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Specifier size
 * Return: Numbers of charshas been printed
 */

int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int i, cnt = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = "(Null)";
	}
	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		cnt++;
	}
	return (cnt);
}


/* PRINT A STRING IN ROT13 *************************/
/**
 * print_rot13string - Prints strings in rot13.
 * @types: Lists of arguments
 * @buffer: Buffer array to handle prints
 * @flags: Checks active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Specifier size
 * Return: Numbers of chars has been printed
 */
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char s;
	char *str;
	unsigned int i, j;
	int cnt = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				s = out[j];
				write(1, &s, 1);
				cnt++;
				break;
			}
		}
		if (!in[j])
		{
			s = str[i];
			write(1, &s, 1);
			cnt++;
		}
	}
	return (cnt);
}
