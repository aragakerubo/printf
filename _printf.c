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
	flags_t flags = {0, 0, 0};
	int (*func)(va_list, flags_t *);

	if (!format)
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	if ((format[0] == '%' && !format[1]) ||
	    (format[0] == '%' && format[1] == '%' && !format[2]))
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
			break;
		while (get_flag(format[i + 1], &flags))
			i++;
		func = get_format(format + i + 1);
		if (func != NULL)
		{
			count += func(list, &flags);
			i += 2;
			continue;
		}
		if (!format[i + 1])
			return (-1);
		_putchar(format[i]);
		count++;
		i += (format[i + 1] == '%') ? 2 : 1;
	}
	va_end(list);
	return (count);
}
