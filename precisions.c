#include "main.h"

/**
 * get_precision - Checks for the precision to be printed
 * @format: Formatted string into print the arguments
 * @i: Lists of arguments to be printed.
 * @list: lists of arguments.
 *
 * Return:the precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int c_i = *i + 1;
	int precise = -1;

	if (format[c_i] != '.')
		return (precise);

	precise = 0;

	for (c_i += 1; format[c_i] != '\0'; c_i++)
	{
		if (is_digit(format[c_i]))
		{
			precise *= 10;
			precise += format[c_i] - '0';
		}
		else if (format[c_i] == '*')
		{
			c_i++;
			precise = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = c_i - 1;

	return (precise);
}
