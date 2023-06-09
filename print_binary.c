#include "main.h"

/**
 * print_binary - prints a binary number
 * @list: binary number to print
 * @flags: flags
 *
 * Description: prints a binary number
 *
 * Return: number of characters printed
 */
int print_binary(
	va_list list,
	__attribute__((unused)) flags_t *flags)
{
	unsigned int n = va_arg(list, unsigned int);
	int count = 0;

	count += binary_num_length(n);
	print_binary_recursion(n);
	return (count);
}

/**
 * binary_num_length - calculates the length of a binary number
 * @n: number to calculate
 *
 * Description: calculates the length of a binary number
 *
 * Return: length of the number
 */
int binary_num_length(unsigned int n)
{
	int length = 0;

	if (n == 0)
		return (1);

	while (n > 0)
	{
		n /= 2;
		length++;
	}
	return (length);
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

