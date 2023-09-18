#include "main.h"
#include <stdarg.h>
#include <stdio.h>

int _printf(const char *format, ...)
{
    int count = 0;
    va_list args;
    va_start(args, format);

    for (; *format; format++)
    {
        if (*format != '%')
	{
            count += _putchar(*format);
        } else if (format[1] != ' ')
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
                default:
                    break;
            }
        }
    }

    va_end(args);
    return count;
}

