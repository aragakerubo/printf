#include "main.h"

/**
 * print_integer - prints an integer
 * @list: integer to print
 *
 * Description: prints an integer
 *
 * Return: number of characters printed
 */
int print_integer(va_list list)
{
	int n = va_arg(list, int);
	int count = 0;

	if (n < 0)
	{
		_putchar('-');
		count++;
		n = -n;
	}
	count += print_number(n);
	return (count);
}

/**
 * print_number - prints a number
 * @n: number to print
 *
 * Description: prints a number
 *
 * Return: number of characters printed
 */
int print_number(int n)
{
	unsigned int num;

	num = n;
	if (num / 10)
		print_number(num / 10);
	_putchar((num % 10) + '0');
	return (num_length(num));
}
