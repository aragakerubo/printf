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

/**
 * num_length - calculates the length of a number
 * @n: number to calculate
 *
 * Description: calculates the length of a number
 *
 * Return: length of the number
 */
int num_length(unsigned int n)
{
	int length = 0;

	if (n == 0)
		return (1);

	while (n > 0)
	{
		n /= 10;
		length++;
	}
	return (length);
}

/**
 * print_unsigned - prints an unsigned integer
 * @list: unsigned integer to print
 *
 * Description: prints an unsigned integer
 *
 * Return: number of characters printed
 */
int print_unsigned(va_list list)
{
	unsigned int n = va_arg(list, unsigned int);
	int count = 0;

	count += num_length(n);
	print_number(n);
	return (count);
}
