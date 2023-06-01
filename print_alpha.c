#include "main.h"

/**
 * print_char - prints a character
 * @list: character to print
 *
 * Description: prints a character
 *
 * Return: number of characters printed
 */
int print_char(va_list list)
{
	_putchar(va_arg(list, int));
	return (1);
}

/**
 * print_string - prints a string
 * @list: string to print
 *
 * Description: prints a string
 *
 * Return: number of characters printed
 */
int print_string(va_list list)
{
	int i = 0;
	char *str = va_arg(list, char *);

	if (!str)
		str = "(null)";
	while (str[i])
		_putchar(str[i++]);
	return (i);
}

/**
 * print_percent - prints a percent
 * @list: percent (do nothing)
 *
 * Description: prints a percent
 *
 * Return: number of characters printed
 */
int print_percent(__attribute__((unused)) va_list list)
{
	_putchar('%');
	return (1);
}
