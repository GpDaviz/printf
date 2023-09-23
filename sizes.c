#include "main.h"

/**
 * get_size - Checks for the size to cast the arguments
 * @format: Format string in which to print the arguments
 * @i: The list of arguments to be printed
 * Return: The Size
 */
int get_size(const char *format, int *i)
{
	int c_i = *i + 1;
	int s = 0;

	if (format[c_i] == 'l')
		s = S_LONG;
	else if (format[c_i] == 'h')
		s = S_SHORT;

	if (s == 0)
		*i = c_i - 1;
	else
		*i = c_i;

	return (s);
}
