#include "main.h"

/**
 * get_format - selects the correct function to perform the operation
 * @format: character string
 *
 * Description: selects the correct function to perform the operation
 *
 * Return: pointer to the function that corresponds
 * to the format given as a parameter
 */
int (*get_format(const char *format))(va_list)
{
	unsigned int i = 0;
	print_t p[] = {
	    {"c", print_char},
	    {"s", print_string},
	    {"%", print_percent},
	    {NULL, NULL}};

	while (p[i].c)
	{
		if (*(p[i].c) == *format)
			break;
		i++;
	}
	return (p[i].f);
}
