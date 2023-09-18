#include "main.h"

/**
 * convert - function to convert
 * @num: is a number
 * @base: the base
 * @flags: the flags of argument
 * @params: the paramater
 * Return: a string
 */
char *convert(long int num, int base, int flags, params_t *params)
{
	static char *arr;
	static char buffer[50];
	char sign = 0;
	char *x;
	unsigned long number = num;
	(void)params;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		number = -num;
		sign = '-';
	}
	arr = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	x = &buffer[49];
	*x = '\0';

	do	{
		*--x = arr[number % base];
		number /= base;
	} while (number != 0);

	if (sign)
		*--x = sign;
	return (x);
}

/**
 * print_unsigned - function prints integer unsigned numbers
 * @az: pointer argument
 * @params: the parameters
 * Return: printed bytes
 */
int print_unsigned(va_list az, params_t *params)
{
	unsigned long x;

	if (params->j_modifier)
		x = (unsigned long)va_arg(az, unsigned long);
	else if (params->g_modifier)
		x = (unsigned short int)va_arg(az, unsigned int);
	else
		x = (unsigned int)va_arg(az, unsigned int);
	params->unsgn = 1;
	return (print_number(convert(x, 10, CONVERT_UNSIGNED, params), params));
}


/**
 * print_address - function prints address
 * @az: the pointer argument
 * @params: the parameters
 * Return: printed bytes
 */
int print_address(va_list az, params_t *params)
{
	unsigned long int number = va_arg(az, unsigned long int);
	char *string;

	if (!number)
		return (_puts("(nil)"));

	string = convert(number, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	*--string = 'x';
	*--string = '0';
	return (print_number(string, params));
}
