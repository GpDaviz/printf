#ifndef MAIN_H
#define MAIN_H


#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>

/* putchar function */
int _putchar(char c);

/* Function prototypes for printing functions */
int print_string(char *str);
int print_decimal(int num);
int print_binary(int num);
int print_unsigned(unsigned int num);

/* _printf function prototype */
int _printf(const char *format, ...);

#endif
