#include "main.h"

/**
 * print_S - prints the string.
 * @list: list of arguments
 * @flags: flags
 * @arg_count: number of arguments
 *
 * Description: prints the string.
 *
 * Return: number of characters printed
 */
int print_S(
	va_list list,
	__attribute__((unused)) flags_t *flags,
	__attribute__((unused)) unsigned int arg_count)
{
	char *str = va_arg(list, char *);
	int i = 0, count = 0;

	if (!str)
		str = "(null)";
	while (str[i])
	{
		if (str[i] > 0 && (str[i] < 32 || str[i] >= 127))
		{
			_putchar('\\');
			_putchar('x');
			if (str[i] < 16)
			{
				_putchar('0');
				count++;
			}
			count += 2;
			count += print_HEX_aux((unsigned int)str[i]);
		}
		else
		{
			_putchar(str[i]);
			count++;
		}
		i++;
	}
	return (count);
}

/**
 * print_HEX_aux - prints the string.
 * @n: number to print
 *
 * Description: prints the string.
 *
 * Return: number of characters printed
 */
int print_HEX_aux(unsigned int n)
{
	int count = 0;
	int remainder;

	if (n / 16)
		count += print_HEX_aux(n / 16);

	remainder = n % 16;
	if (remainder < 10)
		_putchar(remainder + '0');
	else
		_putchar(remainder - 10 + 'A');
	count++;
	return (count);
}

/**
 * print_p - prints the address of a pointer
 * @list: list of arguments
 * @flags: flags
 * @arg_count: number of arguments
 *
 * Description: prints the address of a pointer
 *
 * Return: number of characters printed
 */
int print_p(
	va_list list,
	__attribute__((unused)) flags_t *flags,
	__attribute__((unused)) unsigned int arg_count)
{
	unsigned long int address = va_arg(list, unsigned long int);
	int count = 0;
	char *null = "(nil)";

	if (!address)
	{
		while (*null)
		{
			_putchar(*null);
			null++;
			count++;
		}
		return (count);
	}

	_putchar('0');
	_putchar('x');
	count += 2;
	count += print_hex_aux(address);
	return (count);
}

/**
 * print_hex_aux - prints the string.
 * @n: number to print
 *
 * Description: prints the string.
 *
 * Return: number of characters printed
 */
int print_hex_aux(unsigned long int n)
{
	int count = 0;
	int remainder;

	if (n / 16)
		count += print_hex_aux(n / 16);

	remainder = n % 16;
	if (remainder < 10)
		_putchar(remainder + '0');
	else
		_putchar(remainder - 10 + 'a');
	count++;
	return (count);
}
