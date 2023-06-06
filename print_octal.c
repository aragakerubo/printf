#include "main.h"

/**
 * print_octal - prints an octal
 * @list: octal to print
 * @flags: flags
 * @arg_count: number of arguments
 *
 * Description: prints an octal
 *
 * Return: number of characters printed
 */
int print_octal(
	va_list list,
	flags_t *flags,
	unsigned int arg_count)
{
	unsigned int *arg = malloc(sizeof(unsigned int) * (arg_count + 1));
	unsigned int n, i;
	int count = 0;

	for (i = 0; i < (arg_count + 1); i++)
		arg[i] = va_arg(list, unsigned int);

	n = arg[arg_count];

	if (flags->hash_flag == 1 && n != 0)
	{
		_putchar('0');
		count++;
	}

	count += octal_num_length(n);
	print_octal_recursion(n);
	return (count);
}

/**
 * octal_num_length - calculates the length of an octal
 * @n: octal to calculate
 *
 * Description: calculates the length of an octal
 *
 * Return: length of the octal
 */
int octal_num_length(unsigned int n)
{
	int length = 0;

	if (n == 0)
		return (1);

	while (n > 0)
	{
		n /= 8;
		length++;
	}
	return (length);
}

/**
 * print_octal_recursion - prints an octal recursively
 * @n: octal to print
 *
 * Description: prints an octal recursively
 *
 * Return: void
 */
void print_octal_recursion(unsigned int n)
{
	if (n / 8)
		print_octal_recursion(n / 8);
	_putchar((n % 8) + '0');
}
