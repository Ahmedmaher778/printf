#include "main.h"

/**
 * print_hex - function prints numbers unsigned hex (lowerCase)
 * @ap: the pointer argument
 * @params:  parameters
 * Return: the printed bytes
 */
int print_hex(va_list ap, params_t *params)
{
	unsigned long longLen;
	int y = 0;
	char *string;

	if (params->l_modifier)
		longLen = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		longLen = (unsigned short int)va_arg(ap, unsigned int);
	else
		longLen = (unsigned int)va_arg(ap, unsigned int);

	string = convert(longLen, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	if (params->hashtag_flag && longLen)
	{
		*--string = 'x';
		*--string = '0';
	}
	params->unsign = 1;
	return (y += print_number(string, params));
}

/**
 * print_HEX - function prints numbers unsigned hex (upperCase)
 * @ap: the pointer argument
 * @params: the parameters
 * Return: the printed bytes
 */
int print_HEX(va_list ap, params_t *params)
{
	unsigned long longLen;
	int x = 0;
	char *string;

	if (params->l_modifier)
		longLen = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		longLen = (unsigned short int)va_arg(ap, unsigned int);
	else
		longLen = (unsigned int)va_arg(ap, unsigned int);

	string = convert(longLen, 16, CONVERT_UNSIGNED, params);
	if (params->hashtag_flag && longLen)
	{
		*--string = 'X';
		*--string = '0';
	}
	params->unsign = 1;
	return (x += print_number(string, params));
}
/**
 * print_binary - function prints numbers in unsigned octal
 * @ap: the pointer argument
 * @params: the parameters
 * Return: the printed bytes
 */
int print_binary(va_list ap, params_t *params)
{
	unsigned int num = va_arg(ap, unsigned int);
	char *string = convert(num, 2, CONVERT_UNSIGNED, params);
	int x = 0;

	if (params->hashtag_flag && num)
		*--string = '0';
	params->unsign = 1;
	return (x += print_number(string, params));
}

/**
 * print_octal - function prints numbers in unsigned octal
 * @ap: the pointer argument
 * @params: the parameters
 * Return: the printed bytes
 */
int print_octal(va_list ap, params_t *params)
{
	unsigned long longLen;
	char *string;
	int x = 0;

	if (params->l_modifier)
		longLen = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		longLen = (unsigned short int)va_arg(ap, unsigned int);
	else
		longLen = (unsigned int)va_arg(ap, unsigned int);
	string = convert(longLen, 8, CONVERT_UNSIGNED, params);

	if (params->hashtag_flag && longLen)
		*--string = '0';
	params->unsign = 1;
	return (x += print_number(string, params));
}
