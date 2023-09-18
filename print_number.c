#include "main.h"

/**
 * _isdigit - checks if character is digit
 * @c: character to check
 * Return: 1 if digit, 0 otherwise
*/

int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - returns the length of a string
 * @s: string whose length to check
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
 * Return: chars printed
*/

int print_number(char *str, params_t *params)
{
	unsigned int l = _strlen(str);
	int neg = (!params->unsign && *str == '-');

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

	if (!params->minus_flag)
		return (print_number_right_shift(str, params));
	else
		return (print_number_left_shift(str, params));
}

/**
 * print_number_right_shift - prints a number with options
 * @str: base number as a string
 * @params: parameter struct
 * Return: chars printed
*/

int print_number_right_shift(char *str, params_t *params)
{
	unsgned int v = 0, neg, neg2, l = _strlen(str);
	char pad_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		pad_char = '0';
	neg = neg2 = (!params->unsign && *str == '-');
	if (neg && l < params->width && pad_char == '0' && !params->minus_flag)
		str++;
	else
		neg = 0;
	if ((params->plus_flag && !neg2) ||
		(!params->plus_flag && params->space_flag && !neg2))
		l++;
	if (neg && pad_char == '0')
		v += _putchar('-');
	if (params->plus_flag && !neg2 && pad_char == '0' && !params->unsign)
		v += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !neg2 &&
		!params->unsign && params->zero_flag)
		v += _putchar(' ');
	while (i++ < params->width)
		v += _putchar(pad_char);
	if (neg && pad_char == ' ')
		v += _putchar('-');
	if (params->plus_flag && !neg2 && pad_char == ' ' && !params->unsign)
		v += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !neg2 &&
		!params->unsign && !params->zero_flag)
		v += _putchar(' ');
	v += _puts(str);
	return (v);
}

/**
 * print_number_left_shift - prints a number with options
 * @str: base number as a string
 * @params: parameter struct
 * Return: chars printed
*/

int print_number_left_shift(char *str, params_t *params)
{
	unsigned int v = 0, neg, neg2, l = _strlen(str);
	char pad_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		pad_char = '0';
	neg = neg2 = (!params->unsign && *str == '-');
	if (neg && l < params->width && pad_char == '0' && !params->minus_flag)
		str++;
	else
		neg = 0;

	if (params->plus_flag && !neg2 && !params->unsign)
		v += _putchar('+'), l++;
	else if (params->space_flag && !neg2 && !params->unsign)
		v += _putchar(' '), l++;
	v += _puts(str);
	while (l++ < params->width)
		v += _putchar(pad_char);
	return (v);
}

