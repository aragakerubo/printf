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
	char *str;
	int i, count = 0;

	str = va_arg(list, char *);
	if (!str)
		str = "(null)";
	for (i = 0; str[i]; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			count += 2;
			if (str[i] < 16)
			{
				_putchar('0');
				count++;
			}
			count += print_HEX(str[i]);
		}
		else
		{
			_putchar(str[i]);
			count++;
		}
	}
	return (count);
}
