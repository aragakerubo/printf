#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <limits.h>

/**
 * struct flags - struct
 * @plus_flag: plus flag
 * @space_flag: space flag
 * @hash_flag: hash flag
 */
typedef struct flags
{
	int plus_flag;
	int space_flag;
	int hash_flag;
} flags_t;

/**
 * struct print - struct
 * @c: char
 * @f: function
 */
typedef struct print
{
	char *c;
	int (*f)(va_list, flags_t *);
} print_t;

int _printf(const char *format, ...);
int _putchar(char c);
int (*get_format(const char *format))(va_list, flags_t *);
int print_char(va_list args, flags_t *flags);
int print_string(va_list args, flags_t *flags);
int print_percent(va_list args, flags_t *flags);
int print_integer(va_list args, flags_t *flags);
int print_number(int n);
int num_length(unsigned int n);
int print_binary(va_list args, flags_t *flags);
int binary_num_length(unsigned int n);
void print_binary_recursion(unsigned int n);
int print_unsigned(va_list args, flags_t *flags);
int print_octal(va_list args, flags_t *flags);
int octal_num_length(unsigned int n);
void print_octal_recursion(unsigned int n);
int print_hex(va_list args, flags_t *flags);
int hex_num_length(unsigned int n);
void print_hex_recursion(unsigned int n);
int print_HEX(va_list args, flags_t *flags);
void print_HEX_recursion(unsigned int n);
int print_S(va_list args, flags_t *flags);
int print_HEX_aux(unsigned int n);
int print_p(va_list args, flags_t *flags);
int print_hex_aux(unsigned long int n);
int get_flag(char c, flags_t *flags);

#endif /* MAIN_H */
