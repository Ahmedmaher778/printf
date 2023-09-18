#include "main.h"

/**
 * print_hex - function prints numbers unsigned hex (lowerCase)
 * @az: the pointer argument
 * @params:  parameters
 * Return: the printed bytes
 */
int print_hex(va_list az, params_t *params)
{
	unsigned long len;
	int y = 0;
	char *string;

	if (params->l_modifier)
		len = (unsigned long)va_arg(az, unsigned long);
	else if (params->h_modifier)
		len = (unsigned short int)va_arg(az, unsigned int);
	else
		len = (unsigned int)va_arg(az, unsigned int);

	string = convert(len, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	if (params->hash_flag && len)
	{
		*--string = 'x';
		*--string = '0';
	}
	params->unsgn = 1;
	return (y += print_number(string, params));
}

/**
 * print_HEX - function prints numbers unsigned hex (upperCase)
 * @az: the pointer argument
 * @params: the parameters
 * Return: the printed bytes
 */
int print_HEX(va_list az, params_t *params)
{
	unsigned long len;
	int y = 0;
	char *string;

	if (params->l_modifier)
		len = (unsigned long)va_arg(az, unsigned long);
	else if (params->h_modifier)
		len = (unsigned short int)va_arg(az, unsigned int);
	else
		len = (unsigned int)va_arg(az, unsigned int);

	string = convert(l, 16, CONVERT_UNSIGNED, params);
	if (params->hash_flag && len)
	{
		*--string = 'X';
		*--string = '0';
	}
	params->unsgn = 1;
	return (y += print_number(string, params));
}
/**
 * print_binary - function prints unsigned number
 * @az: the pointer argument
 * @params: the parameters
 * Return: the printed bytes
 */
int print_binary(va_list az, params_t *params)
{
	unsigned int num = va_arg(az, unsigned int);
	char *string = convert(num, 2, CONVERT_UNSIGNED, params);
	int y = 0;

	if (params->hash_flag && num)
		*--string = '0';
	params->unsgn = 1;
	return (y += print_number(string, params));
}

/**
 * print_octal - function prints numbers in unsigned octal
 * @az: the pointer argument
 * @params: the parameters
 * Return: the printed bytes
 */
int print_octal(va_list az, params_t *params)
{
	unsigned long len;
	char *string;
	int y = 0;

	if (params->l_modifier)
		len = (unsigned long)va_arg(az, unsigned long);
	else if (params->h_modifier)
		len = (unsigned short int)va_arg(az, unsigned int);
	else
		len = (unsigned int)va_arg(az, unsigned int);
	string = convert(len, 8, CONVERT_UNSIGNED, params);

	if (params->hash_flag && len)
		*--string = '0';
	params->unsgn = 1;
	return (y += print_number(string, params));
}
