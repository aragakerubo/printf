#include "main.h"

/**
 * print_hex - prints a hexadecimal
 * @list: hexadecimal to print
 * @flags: flags
 * @arg_count: number of arguments
 *
 * Description: prints a hexadecimal
 *
 * Return: number of characters printed
 */
int print_hex(
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
		_putchar('x');
		count += 2;
	}

	count += hex_num_length(n);
	print_hex_recursion(n);
	return (count);
}

/**
 * hex_num_length - calculates the length of a hexadecimal
 * @n: number to calculate
 *
 * Description: calculates the length of a hexadecimal
 *
 * Return: length of the number
 */
int hex_num_length(unsigned int n)
{
	int length = 0;

	if (n == 0)
		return (1);

	while (n > 0)
	{
		n /= 16;
		length++;
	}
	return (length);
}

/**
 * print_hex_recursion - prints a hexadecimal
 * @n: hexadecimal to print
 *
 * Description: prints a hexadecimal
 *
 * Return: void
 */
void print_hex_recursion(unsigned int n)
{
	if (n / 16)
		print_hex_recursion(n / 16);
	if ((n % 16) < 10)
		_putchar((n % 16) + '0');
	else
		_putchar((n % 16) - 10 + 'a');
}

/**
 * print_HEX - prints a hexadecimal
 * @list: hexadecimal to print
 * @flags: flags
 * @arg_count: number of arguments
 *
 * Description: prints a hexadecimal
 *
 * Return: number of characters printed
 */
int print_HEX(
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
		_putchar('X');
		count += 2;
	}

	count += hex_num_length(n);
	print_HEX_recursion(n);
	return (count);
}

/**
 * print_HEX_recursion - prints a hexadecimal
 * @n: hexadecimal to print
 *
 * Description: prints a hexadecimal
 *
 * Return: void
 */
void print_HEX_recursion(unsigned int n)
{
	if (n / 16)
		print_HEX_recursion(n / 16);
	if ((n % 16) < 10)
		_putchar((n % 16) + '0');
	else
		_putchar((n % 16) - 10 + 'A');
}
