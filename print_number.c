#include "main.h"

/**
 * _isdigit - checks if character is digit
 * @x: character to check
 *
 * Return: 1 if digit, 0 otherwise
*/

int _isdigit(int x)
{
	return (x >= '0' && x <= '9');
}

/**
 * _strlen - returns the length of a string
 * @s: string whose length to check
 *
 * Return: integer string length
*/

int _strlen(char *s)
{
	int l = 0;

	while (*s++)
		l++;
	return (l);
}

/**
 * print_number - prints a number with options
 * @str: base number as a string
 * @params: parameter struct
 *
 * Return: chars printed
*/

int print_number(char *str, params_r *params)
{
	unsigned int l = _strlen(str);
	int neg = (!params->unsgn && *str == '-');

	if (!params->precision && *str == '0' && !str[1])
		str = "";
	if (neg)
	{
		str++;
		l--;
	}
	if (params->precision != UINT_MAX)
		while (l++ < params->precision)
			*--str = '0';
	if (neg)
		*--str = '-';

	if (!params->m_flag)
		return (print_number_right_shift(str, params));
	else
		return (print_number_left_shift(str, params));
}

/**
 * print_number_right_shift - prints a number with options
 * @str: base number as a string
 * @params: parameter struct
 *
 * Return: chars printed
*/

int print_number_right_shift(char *str, params_r *params)
{
	unsgned int v = 0, neg, neg2, l = _strlen(str);
	char pad_char = ' ';

	if (params->z_flag && !params->m_flag)
		pad_char = '0';
	neg = neg2 = (!params->unsgn && *str == '-');
	if (neg && l < params->wid && pad_char == '0' && !params->m_flag)
		str++;
	else
		neg = 0;
	if ((params->plus_flag && !neg2) ||
		(!params->pl_flag && params->sp_flag && !neg2))
		l++;
	if (neg && pad_char == '0')
		v += _putchar('-');
	if (params->pl_flag && !neg2 && pad_char == '0' && !params->unsgn)
		v += _putchar('+');
	else if (!params->pl_flag && params->sp_flag && !neg2 &&
		!params->unsgn && params->z_flag)
		v += _putchar(' ');
	while (l++ < params->wid)
		v += _putchar(pad_char);
	if (neg && pad_char == ' ')
		v += _putchar('-');
	if (params->pl_flag && !neg2 && pad_char == ' ' && !params->unsgn)
		v += _putchar('+');
	else if (!params->pl_flag && params->sp_flag && !neg2 &&
		!params->unsgn && !params->z_flag)
		n += _putchar(' ');
	v += _puts(str);
	return (v);
}

/**
 * print_number_left_shift - prints a number with options
 * @str: base number as a string
 * @params: parameter struct
 *
 * Return: chars printed
*/

int print_number_left_shift(char *str, params_r *params)
{
	unsigned int v = 0, neg, neg2, l = _strlen(str);
	char pad_char = ' ';

	if (params->z_flag && !params->m_flag)
		pad_char = '0';
	neg = neg2 = (!params->unsgn && *str == '-');
	if (neg && l < params->wid && pad_char == '0' && !params->m_flag)
		str++;
	else
		neg = 0;

	if (params->pl_flag && !neg2 && !params->unsgn)
		v += _putchar('+'), l++;
	else if (params->sp_flag && !neg2 && !params->unsgn)
		v += _putchar(' '), l++;
	v += _puts(str);
	while (l++ < params->wid)
		v += _putchar(pad_char);
	return (v);
}

