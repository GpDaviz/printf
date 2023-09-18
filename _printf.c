#include "main.h"

/**
 * _printf - a function that prints to the standard output just like printf
 * @format: constant string to be printed
 * Return: converted integer
 */

int _printf(const char *format, ...)
{
	unsigned int count = 0;
	va_list args;

	va_start(args, format);
	for (; *format; format++)
	{
		if (*format != '%')
			count += _putchar(*format);
		else if (format[1] != ' ')
		{
			format++;
			switch (*format)
			{
				case 'c':
				count += _putchar(va_arg(args, int));
				break;
				case 's':
				count += print_string(va_arg(args, char *));
				break;
				case '%':
				count += _putchar('%');
				break;
				case 'd':
				case 'i':
				count += print_decimal(va_arg(args, int));
				break;
				case 'b':
				count += print_binary(va_arg(args, int));
				break;
				case 'u':
				count += print_unsigned(va_arg(args, unsigned int));
				break;
				case 'r':
				count += _putchar('%');
				count += _putchar('r');
				default:
				break;
			}
		}
	}
	va_end(args);
	return (count);
}

