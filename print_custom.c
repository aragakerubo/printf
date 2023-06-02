#include "main.h"

/**
 * print_S - prints the string.
 * @list: list of arguments
 *
 * Description: prints the string.
 *
 * Return: number of characters printed
 */
int print_S(va_list list)
{
	char *str = va_arg(list, char *);
	int i = 0, count = 0;

	if (!str)
		str = "(null)";
	while (str[i])
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			count += 2;
			count += print_HEX_aux((unsigned char)str[i]);
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
 *
 * Description: prints the address of a pointer
 *
 * Return: number of characters printed
 */
int print_p(va_list list)
{
	void *p = va_arg(list, void *);
	unsigned long int address = (unsigned long int)p;
	int count = 0;

	_putchar('0');
	_putchar('x');
	count += 2;
	count += print_HEX_aux(address);
	return (count);
}
