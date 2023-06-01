#include "main.h"

/**
 * print_binary - prints a binary number
 * @list: binary number to print
 *
 * Description: prints a binary number
 *
 * Return: number of characters printed
 */
int print_binary(va_list list)
{
	unsigned int n = va_arg(list, unsigned int);
	int count = 0;

	count += num_length(n);
	print_binary_recursion(n);
	return (count);
}

/**
 * print_binary_recursion - prints a binary number
 * @n: binary number to print
 *
 * Description: prints a binary number
 *
 * Return: void
 */
void print_binary_recursion(unsigned int n)
{
	if (n / 2)
		print_binary_recursion(n / 2);
	_putchar((n % 2) + '0');
}

