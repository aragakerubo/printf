#include "main.h"

/**
 * _printf - prints output according to a format
 * @format: character string
 *
 * Description: produces output according to a format
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	unsigned int i = 0, count = 0;
	va_list list;
	int (*func)(va_list);

	if (!format)
		return (-1);
	va_start(list, format);
	while (format[i])
	{
		while (format[i] != '%' && format[i])
		{
			_putchar(format[i]);
			count++;
			i++;
		}
		if (!format[i])
			return (count);
		func = get_format(format + i + 1);
		if (func != NULL)
		{
			count += func(list);
			i += 2;
			continue;
		}
		if (!format[i + 1])
			return (-1);
		_putchar(format[i]);
		count++;
		if (format[i + 1] == '%')
			i += 2;
		else
			i++;
	}
	va_end(list);
	return (count);
}
