#include "main.h"

/**
 * print_integer - prints an integer
 * @list: integer to print
 * @flags: flags
 * @arg_count: number of arguments
 *
 * Description: prints an integer
 *
 * Return: number of characters printed
 */
int print_integer(va_list list, flags_t *flags, unsigned int arg_count)
{
	int *arg = malloc(sizeof(int) * (arg_count + 1));
	unsigned int i;
	int count = 0, n;

	for (i = 0; i < (arg_count + 1); i++)
		arg[i] = va_arg(list, int);

	n = arg[arg_count];
	if (flags->space_flag == 1 && flags->plus_flag == 0 && n >= 0)
		count += _putchar(' ');

	if (flags->plus_flag == 1 && n >= 0)
		count += _putchar('+');

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
 * @flags: flags
 * @arg_count: number of arguments
 *
 * Description: prints an unsigned integer
 *
 * Return: number of characters printed
 */
int print_unsigned(
	va_list list,
	__attribute__((unused)) flags_t *flags,
	__attribute__((unused)) unsigned int arg_count)
{
	unsigned int n = va_arg(list, unsigned int);
	int count = 0;

	count += num_length(n);
	print_number(n);
	return (count);
}
