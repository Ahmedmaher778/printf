#include "main.h"

/**
 * get_precision - function to get the precision
 * @b: string
 * @params: parameters
 * @az: the argument pointer
 * Return: a pointer
 */

char *get_precision(char *b, params_r *params, va_list az)
{
	int x = 0;

	if (*b != '.')
		return (b);
	b++;
	if (*b == '*')
	{
		x = va_arg(az, int);
		b++;
	}
	else
	{
		while (_isdigit(*b))
			x = x * 10 + (*b++ - '0');
	}
	params->precision = x;
	return (b);
}
