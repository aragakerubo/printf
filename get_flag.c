#include "main.h"

/**
 * get_flag - finds the flag
 * @c: character to check
 * @flags: flags
 *
 * Description: finds the flag
 *
 * Return: 1 if flag found, 0 if not
 */
int get_flag(char c, flags_t *flags)
{
	switch (c)
	{
	case '+':
		flags->plus_flag = 1;
		break;
	case ' ':
		flags->space_flag = 1;
		break;
	case '#':
		flags->hash_flag = 1;
		break;
	default:
		return (0);
	}
	return (1);
}
