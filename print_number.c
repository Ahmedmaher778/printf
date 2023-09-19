#include "main.h"

/**
 * _isdigit - checks if character is digit
 * @c: the character to check
 * Return: 1 if digit, 0 otherwise
*/

int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - returns the length of a string
 * @s: string whose length to check
 * Return: integer length of string
*/

int _strlen(char *s)
{
	int i = 0;

	while (*s++)
		i++;
	return (i);
}

/**
 * print_number - prints number with options
 * @str: base number as string
 * @params: parameter struct
 * Return: chars printed
*/

int print_number(char *str, params_t *params)
{
	unsigned int i = _strlen(str);
	int n1 = (!params->unsign && *str == '-');

	if (!params->precision && *str == '0' && !str[1])
		str = "";
	if (n1)
	{
		str++;
		i--;
	}
	if (params->precision != UINT_MAX)
		while (i++ < params->precision)
			*--str = '0';
	if (n1)
		*--str = '-';

	if (!params->minus_flag)
		return (print_number_right_shift(str, params));
	else
		return (print_number_left_shift(str, params));
}

/**
 * print_number_right_shift - prints number with options
 * @str: base number as a string
 * @params: parameter struct
 * Return: chars printed
*/

int print_number_right_shift(char *str, params_t *params)
{
	unsigned int n = 0, n1, n2, i = _strlen(str);
	char pad_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		pad_char = '0';
	n1 = n2 = (!params->unsign && *str == '-');
	if (n1 && i < params->width && pad_char == '0' && !params->minus_flag)
		str++;
	else
		n1 = 0;
	if ((params->plus_flag && !n2) ||
		(!params->plus_flag && params->space_flag && !n2))
		i++;
	if (n1 && pad_char == '0')
		n += _putchar('-');
	if (params->plus_flag && !n2 && pad_char == '0' && !params->unsign)
		n += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !n2 &&
		!params->unsign && params->zero_flag)
		n += _putchar(' ');
	while (i++ < params->width)
		n += _putchar(pad_char);
	if (n1 && pad_char == ' ')
		n += _putchar('-');
	if (params->plus_flag && !n2 && pad_char == ' ' && !params->unsign)
		n += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !n2 &&
		!params->unsign && !params->zero_flag)
		n += _putchar(' ');
	n += _puts(str);
	return (n);
}

/**
 * print_number_left_shift - prints number with options
 * @str: base number as a string
 * @params: parameter struct
 * Return: chars printed
*/

int print_number_left_shift(char *str, params_t *params)
{
	unsigned int n = 0, n1, n2, i = _strlen(str);
	char pad_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		pad_char = '0';
	n1 = n2 = (!params->unsign && *str == '-');
	if (n1 && i < params->width && pad_char == '0' && !params->minus_flag)
		str++;
	else
		n1 = 0;

	if (params->plus_flag && !n2 && !params->unsign)
		n += _putchar('+'), i++;
	else if (params->space_flag && !n2 && !params->unsign)
		n += _putchar(' '), i++;
	n += _puts(str);
	while (i++ < params->width)
		n += _putchar(pad_char);
	return (n);
}
