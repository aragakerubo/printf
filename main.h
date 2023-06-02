#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <limits.h>

/**
 * struct print - struct
 * @c: char
 * @f: function
 */
typedef struct print
{
	char *c;
	int (*f)(va_list);
} print_t;

int _printf(const char *format, ...);
int _putchar(char c);
int (*get_format(const char *format))(va_list);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_integer(va_list args);
int print_number(int n);
int num_length(unsigned int n);
int print_binary(va_list args);
int binary_num_length(unsigned int n);
void print_binary_recursion(unsigned int n);
int print_unsigned(va_list args);
int print_octal(va_list args);
int octal_num_length(unsigned int n);
void print_octal_recursion(unsigned int n);
int print_hex(va_list args);
int hex_num_length(unsigned int n);
void print_hex_recursion(unsigned int n);
int print_HEX(va_list args);
void print_HEX_recursion(unsigned int n);
int print_S(va_list args);
int print_HEX_aux(unsigned int n);
int print_p(va_list args);
int print_hex_aux(unsigned long int n);

#endif /* MAIN_H */
