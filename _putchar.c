#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	static char buf[1024];
	static int i;

	if (c == '\n' || i == 1024)
	{
		write(1, buf, i);
		i = 0;
	}

	if (c != '\n')
	{
		buf[i] = c;
		i++;
	}

	return (1);
}
